class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>col(m,vector<int>(n,0));
        vector<vector<int>>row(m,vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0){
                    row[i][j] = grid[i][j];
                }
                else if(grid[i][j] == 1){
                    row[i][j] = row[i][j-1]+1;
                }

            }

        }
         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j == 0){
                    col[j][i] = grid[j][i];
                }
                else if(grid[j][i] == 1){
                    col[j][i] = col[j-1][i]+1;
                }

            }

        }

        int k = min(n,m);
        int ans = 0;
        for(int s = 1; s <= k; s++){
            for(int i = s-1; i < m; i++){
                for(int j = s-1; j < n; j++){
                    if(col[i][j] >= s){
                        if(col[i][j-s+1] >= s && row[i][j] >= s && row[i-s+1][j] >=s){
                            ans = s;
                        }

                    }
                }
            }
        }
        return ans*ans;
    }
};
