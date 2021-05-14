class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>>dp(n,vector<double>(n,0));
        dp[row][column] = 1;
        int xdir[8] = {2,2,1,1,-1,-1,-2,-2};
        int ydir[8] = {1,-1,2,-2,2,-2,1,-1};
        for(; k > 0; k--){
            vector<vector<double>>temp(n,vector<double>(n,0));
            for(int r = 0; r < n; r++){
                for(int c = 0; c < n; c++){
                    for(int i = 0 ; i< 8; i++){
                        int nr = r + xdir[i];
                        int nc = c + ydir[i];
                        if(nr >=0 && nc >=0 && nr < n && nc < n){
                            temp[nr][nc] += dp[r][c]/ 8.0;
                        }
                    }
                }
            }
            dp = temp;
        }
        double ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
