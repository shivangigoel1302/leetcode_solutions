class Solution {
public:

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>subordinates(n);
        for(int i = 0 ; i < manager.size(); i++){
            if(manager[i] == -1){
                continue;
            }
            else{
                subordinates[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        q.push({headID,0});
        int ans = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int time = p.second;
            ans = max(ans,time);
            for(auto s : subordinates[p.first]){
                q.push({s,time + informTime[p.first]});
            }
        }
        return ans;
    }
};
