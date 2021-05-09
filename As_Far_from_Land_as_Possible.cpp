class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        queue<pair<int,int>>q;
        int xdir[8] ={0,-1,-1,-1,0,1,1,1};
        int ydir[8] ={1,1,0,-1,-1,-1,0,1};
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }
        int maximum = INT_MIN;
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            for(int i = 0 ; i < 8; i++){
                int nr = f.first + xdir[i];
                int nc = f.second + ydir[i];
                if(nr < m && nr >= 0 && nc >= 0 && nc < n && grid[nr][nc] != 1){
                    if(dist[nr][nc] > dist[f.first][f.second] + abs(nr-f.first) + abs(nc - f.second)){
                        dist[nr][nc] = dist[f.first][f.second] + abs(nr-f.first) + abs(nc - f.second);
                        q.push({nr,nc});
                    }
                }
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n; j++){
                maximum = max(maximum,dist[i][j]);
            }
        }
        if(maximum == INT_MAX || maximum == 0){
            return -1;
        }
        return maximum;
    }
};
