class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                dp[i][j] = mat[i][j];
                if(i-1 >=0 && j-1 >=0){
                    dp[i][j] += dp[i-1][j] + dp[i][j-1] -dp[i-1][j-1];
                }
                else if(i-1 >=0){
                    dp[i][j] += dp[i-1][j];
                }
                else if(j-1>=0){
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i = 0 ; i < n; i++){
            int ra = max(0,i-K);
            int rb = min(n-1,i+K);
            for(int j = 0 ; j < m ; j++){
                int ca = max(0,j-K);
                int cb = min(m-1,j+K);
                ans[i][j] = dp[rb][cb];
                if(ra-1 >=0 && ca-1>=0){
                    ans[i][j] = ans[i][j] - dp[ra-1][cb] - dp[rb][ca-1] + dp[ra-1][ca-1];
                }
                else if(ra-1>=0){
                    ans[i][j] = ans[i][j] - dp[ra-1][cb];
                }
                else if(ca -1 >=0){
                    ans[i][j] = ans[i][j] - dp[rb][ca-1];
                }
            }
        }
        return ans;
    }
};
