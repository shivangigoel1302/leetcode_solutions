class Solution {
public:
    int findparent(vector<int>&parent, int v){
        if(parent[v] == -1) return v;
        return parent[v] = findparent(parent,parent[v]);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        int n = s.size();
        vector<int>parent(n, -1);
        for(auto p : pairs){
            int x = findparent(parent,p[0]);
            int y = findparent(parent,p[1]);
            if(x != y){
                parent[x] = y;
            }
        }
         unordered_map<int,vector<int>>m(n);
        for(int i = 0 ; i < n ; i++){
            m[findparent(parent,i)].push_back(i);
        }
        for(auto &it : m){
            string str;
            for(auto index: it.second){
                str += s[index];
            }
            sort(str.begin(),str.end());
            int i = 0;
            for(auto index: it.second){
                s[index] = str[i++];
            }
        }
        return s;
    }
};
