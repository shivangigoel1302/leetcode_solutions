class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
        map<int,int>m;
        set<pair<int,int>>s;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto it:m)
        {

            s.insert(make_pair(it.second,it.first));
        }

        for (auto i = s.rbegin(); i != s.rend(); ++i)
        {
            if(k==0)
            {
                break;
            }
            v.push_back(i->second);
            k--;

        }
        return v;
    }
};
