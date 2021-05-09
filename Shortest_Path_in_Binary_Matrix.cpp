class Solution {
public:
    int x[8] = {1,1,1,0,0,-1,-1,-1};
    int y[8] = {0,1,-1,1,-1,1,0,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
       vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = 1;

        q.push({0,0});

        while(!q.empty()){
            auto f = q.front();
            q.pop();

            for(int i = 0 ; i < 8 ; i++){
                int r = f.first + x[i];
                int c = f.second + y[i];
                if( r >=0 && r < n && c < n && c >=0){
                    if(grid[r][c] != 1){
                         if(dist[r][c] > dist[f.first][f.second]+1){
                            dist[r][c] = dist[f.first][f.second] +1;

                            q.push({r,c});
                        }
                    }

                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX) return -1;
        return dist[n-1][n-1] ;

    }
};
