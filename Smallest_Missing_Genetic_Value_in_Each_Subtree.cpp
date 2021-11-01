class Solution {
public:

    void dfs(int src,vector<int>adj[],vector<int>&visited,vector<int>&nums){
        visited[nums[src]] = 1;
        for(auto nbr: adj[src]){
            if(!visited[nums[nbr]]){
                dfs(nbr,adj,visited,nums);
            }
        }
        return;
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        vector<int>adj[n];
        vector<int>visited(n+2,0);
        vector<int>ans(n,1);
        for(int i = 0; i < parents.size(); i++){
            if(parents[i] == -1){
                continue;
            }
            adj[parents[i]].push_back(i);
        }
        unordered_map<int,int>m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] = i;
        }
        int currmiss = 1;
        if(m.find(1) != m.end()){
            int idx = m[1];
            while(idx != -1){
                dfs(idx,adj,visited,nums);
                while(visited[currmiss]){
                    currmiss++;
                }
                ans[idx] = currmiss;
                idx = parents[idx];
            }
        }
        return ans;

    }
};
