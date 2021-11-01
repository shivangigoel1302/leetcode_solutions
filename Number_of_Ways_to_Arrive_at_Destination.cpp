class Solution {
public:

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(int i = 0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
             adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,pair<int,int>>,vector<pair<long long,pair<int,int>>>,greater<pair<long long,pair<int,int>>>>pq;
        vector<int>visited(n,0);
        vector<long long>dist(n,INT_MAX);
        vector<long long>visits(n,0);
        visits[0] = 1;
        pq.push({0,{0,0}});
        int mod = 1000000007;

        while(!pq.empty()){
            auto f = pq.top();
            pq.pop();
            if(visited[f.second.first]){
                if(dist[f.second.first] == f.first){
                    long long temp = visits[f.second.first] + visits[f.second.second];
                    visits[f.second.first] = (temp)%mod;
                }
                continue;
            }
            visited[f.second.first] = 1;
            visits[f.second.first] = visits[f.second.second];
            dist[f.second.first] = f.first;
            for(auto nbr: adj[f.second.first]){
                int nxnode = nbr.first;
                int w = nbr.second;
                pq.push({w+f.first,{nxnode,f.second.first}});
            }

        }
        return visits[n-1];
    }
};
