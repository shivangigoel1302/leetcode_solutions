class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        vector<bool>visited(n,false);
        for(int i = 0 ; i < edges.size(); i++){
            vector<int>e = edges[i];
            adj[e[0]].push_back({e[1],succProb[i]});
            adj[e[1]].push_back({e[0],succProb[i]});
        }

        queue<int>q;
        vector<double>probab(n,0);
        probab[start] = 1;
        q.push(start);
        double ans = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(x == end){
                continue;
            }
            for(auto j: adj[x]){
                if(probab[j.first] < probab[x]*j.second){
                    probab[j.first] = probab[x]*j.second;
                    q.push(j.first);
                }
            }
        }
        return probab[end];
    }
};
