class Solution {
public:
    int longestPalindromeSubseq(string s) {
       int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = 0 ; i < n +1 ; i++){
            dp[i][i] = 1;
        }
        for(int i = 1; i <= n ; i++){
            for(int j = 0 ; j < n-i+1 ; j++){
                dp[j][j+i] = s[j] == s[j+i] ? 2+ dp[j+1][j+i-1] : max(dp[j][j+i-1],dp[j+1][j+i]);
            }
        }
        return dp[0][n];
    }
};
