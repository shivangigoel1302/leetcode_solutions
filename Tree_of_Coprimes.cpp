class Solution {
public:
    int time;
    void dfs(vector<int>&ans,vector<vector<pair<int,int>>>&ancestors,vector<int>&visited,vector<int>adj[],vector<int>&nums,int root,int parent){
        if(parent != -1){
            ancestors[nums[parent]].push_back({parent,time});
        }
        time++;
        for(auto nbr: adj[root]){
            if(!visited[nbr]){
                visited[nbr] = 1;
                dfs(ans,ancestors,visited,adj,nums,nbr,root);
            }
        }

        int prevtime = -1;
        for(int i =1; i < 51; i++){
            if(__gcd(nums[root],i) == 1){
                if(ancestors[i].size() > 0 && ancestors[i].back().second > prevtime){
                    ans[root] = ancestors[i].back().first;
                    prevtime = ancestors[i].back().second;
                }
            }
        }
        if(parent != -1){
            ancestors[nums[parent]].pop_back();
        }
        time--;
        return;
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int>adj[n];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        time = 0;
        vector<int>visited(n,0);
        vector<vector<pair<int,int>>>ancestors(51);
        vector<int>ans(n,-1);
        visited[0] = 1;
        dfs(ans,ancestors,visited,adj,nums,0,-1);
        return ans;
    }
};
