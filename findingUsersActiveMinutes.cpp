class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,unordered_set<int>>m;
        for(int i = 0 ; i < logs.size(); i++){
            m[logs[i][0]].insert(logs[i][1]);
        }
        vector<int>ans(k,0);
        for(auto it:m){
            ans[it.second.size()-1]++;
        }
        return ans;
    }
};
