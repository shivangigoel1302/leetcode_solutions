class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int size = A.size();
        int dp[size][size];
        for(int i = 0 ; i < size ; i ++){
            dp[0][i] =  A[0][i];
        }
        for(int i = 1 ; i < size ; i ++){
            for(int j = 0 ; j < size; j++){
                dp[i][j] = INT_MAX;
                if(j-1 >=0){
                    dp[i][j] = A[i][j]+ dp[i-1][j-1];
                }
                if(j+1 < A.size()){
                     dp[i][j] = min(dp[i][j], A[i][j]+ dp[i-1][j+1]);
                }
                dp[i][j] = min(dp[i][j], A[i][j] + dp[i-1][j]);
            }
        }
        int ans = INT_MAX;
        for(int i = 0 ; i < size ; i++){
            if(dp[size-1][i] < ans){
                ans = dp[size-1][i];
            }
        }
        return ans;
    }
};
