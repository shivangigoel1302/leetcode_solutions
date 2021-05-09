class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        if(grid.size() == 0) return 0;
        q.push({0,0});
        int x[4]= {0,0,1,-1};
        int y[4] = {1,-1,0,0};
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        dist[0][0] = 0;
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int r = f.first + x[i];
                int c = f.second + y[i];
                if(r >=0 && r < grid.size() && c >=0 && c< grid[0].size()){
                    if(dist[r][c] > max(dist[f.first][f.second],abs(grid[r][c] - grid[f.first][f.second]))){
                        dist[r][c] = max(dist[f.first][f.second],abs(grid[r][c] - grid[f.first][f.second]));
                        q.push({r,c});
                    }
                }
            }
        }
        return dist[grid.size()-1][grid[0].size()-1];
    }
};
