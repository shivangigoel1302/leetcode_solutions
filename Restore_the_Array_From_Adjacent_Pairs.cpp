class Solution {
public:

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>m;
        for(auto i : adjacentPairs){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        int x;
        vector<int>ans(m.size());
        for(auto i : m){
            if(i.second.size() == 1){
                x = i.first;
                break;
            }
        }
        unordered_set<int>visited;
        int curr = x;
        visited.insert(curr);
        int csize = 0;
        while(true){
            ans[csize]=curr;
            csize++;
            if(csize == ans.size()){
                break;
            }
            for(auto i :m[curr]){
                if(visited.count(i)){
                    continue;
                }
                visited.insert(i);
                curr = i;

            }
        }
        return ans;
    }
};
