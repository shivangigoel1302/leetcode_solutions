class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool>visited(points.size());
        int n = points.size();
        int connected = 0;
        int i = 0;
        priority_queue<pair<int,int>>pq;
        vector<int>dist(n,1e7);
        int ans = 0;
        while(++connected < n){
            dist[i] = INT_MAX;
            int minj = i;
            for(int j = 0; j < n; j++){
                if(dist[j] != INT_MAX){
                    dist[j] = min(dist[j],abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                    if(dist[j] < dist[minj]){
                        minj = j;
                    }
                }
            }
            ans += dist[minj];
            i = minj;
        }
        return ans;
    }
};
