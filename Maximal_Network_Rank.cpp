class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n,0);
        vector<vector<int>>graph(n,vector<int>(n,0));
        for(auto e: roads){
            indegree[e[0]]++;
            indegree[e[1]]++;
            graph[e[0]][e[1]] = 1;
            graph[e[1]][e[0]] = 1;
        }
        int ans = 0;
       for(int i = 0 ; i < n; i++){
           for(int j = i+1; j < n; j++){
               int a = indegree[i] + indegree[j];
               if(graph[i][j]){
                   a--;
               }
               ans = max(ans,a);
           }
       }
        return ans;
    }
};
