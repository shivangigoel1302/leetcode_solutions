class Solution {
public:
    void dfs(vector<int>adj[],int src,double p, vector<double>&probab,int target,int t,vector<int>&visited){
        if(t < 0){
            return;
        }
        visited[src] = 1;
        probab[src] = p;
        if(src == target && t != 0 && adj[src].size()-1 != 0){
            probab[src] = 0;
            return;
        }
        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                double temp = p*((1)/((adj[src].size()-1)*1.0));
                dfs(adj,nbr,temp,probab,target,t-1,visited);
            }
        }
        return;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<double>probab(n+1,0);
        vector<int>adj[n+1];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        adj[1].push_back(0);
        vector<int>visited(n+1,0);
        visited[0] = 1;
        dfs(adj,1,1,probab,target,t,visited);
        return probab[target];
    }
};
