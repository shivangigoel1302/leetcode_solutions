class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>>dp(mat.size(),vector<int>(mat[0].size()));
        int m = mat.size();
        int n = mat[0].size();
        dp[0][0] = mat[0][0];
        int ans = 0;
        ans = dp[0][0] <= threshold ?1:0;
        for(int i = 1 ; i < m ; i++){
            dp[i][0] = dp[i-1][0]+mat[i][0]+dp[i][0];
            if(mat[i][0] <= threshold){
                ans = 1;
            }
        }
        for(int i = 1; i < n ; i++){
            dp[0][i] += dp[0][i-1] + mat[0][i];
            if(mat[0][i] <= threshold){
                ans = 1;
            }
        }
        for(int i = 1; i < m ;i++){
            for(int j = 1; j < n ; j++){
                dp[i][j] = mat[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }

        for(int i = 1 ; i < m; i++){
            for(int j = 1; j < n ; j++){
               int r = i-1;
               int c = j-1;
                while(r >=0 && c >=0){
                    int cursum = dp[i][j] -dp[r][j] - dp[i][c] + dp[r][c];
                    if(cursum <= threshold){
                        ans = max(ans,i-r);
                    }
                    r--;
                    c--;
                }
                if(r<0 && c <0){
                    if(dp[i][j] <= threshold){
                        ans = max(ans,i+1);
                    }
                }
            }
        }
        return ans;
    }
};
