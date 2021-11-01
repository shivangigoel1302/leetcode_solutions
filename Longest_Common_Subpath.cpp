class Solution {
public:

    int longestCommonSubpath(int n, vector<vector<int>>& ps)
    {
        //choose the smallest length path of the given paths
        int l = 0, r = min_element(begin(ps), end(ps), [](const auto& a, const auto &b){ return a.size() < b.size(); })->size();
        //base-->p in rabin karp.
        int base = 100001, mod = 1000000007;
        //binary search
        while (l < r)
        {
            //check if common path of length m exists
            int m = (l + r + 1) / 2;
            //hs is map to store possible key value pair of hashes and their starting position in the previous path.
            unordered_map<int, vector<int>> hs;
            for (int i = 0; i < ps.size() && (i == 0 || !hs.empty()); ++i)//break the loop if hs is empty of no possible path exists
            {
                long long hash = 0, d = 1; //d stores the required power of base.
                unordered_map<int, vector<int>> hs1;//map to store the found hashes in current path.
                for (int j = 0; j < ps[i].size(); ++j) //check all the paths
                {
                    hash = (hash * base + ps[i][j]) % mod;//the first element in the hash has max power. i.e hash  is path[i][0]*base^(m-1)+path[i][1]*base^(m-2)+....+path[i][path[i].size()-1]*base^(0)
                    if (j >= m)//remove the extra element in the front
                    {
                        hash = (mod + hash - d * ps[i][j - m] % mod) % mod;
                    }
                    else//increase the power of base
                    {
                        d = d * base % mod;
                    }
                    if (j >= m - 1) //we find a new hash every index from j=m-1
                    {
                        if (i == 0)//if this is first path, there is no hash to compare if this hash is valid with prev path
                        {
                            hs1[hash].push_back(j + 1 - m);
                        }
                        else
                        {
                            if (hs.count(hash))//if this hash exists in prev path, then check if the path is exactly same(even though this is O(m) this operation is executed very less time..so does not include in time complexity)
                            {
                                for (auto pos : hs[hash])
                                {
                                    if (equal(begin(ps[0]) + pos, begin(ps[0]) + pos + m, begin(ps[i]) + j + 1 - m))
                                    {
                                        hs1[hash].push_back(pos);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                swap(hs, hs1);//current map becomes previous map for next path
            }
            if (hs.empty())//if we have no valid hash, it means there is no common paths of this size. Need to decrease serach space to less than that of m.
            {
                r = m - 1;
            }
            else//we have a set of commom paths of size m. Now check for longer paths.
            {
                l = m;
            }
        }
        return l;
    }
};
