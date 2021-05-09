class Solution {
public:
    int len(string s, string y, int m , int n){
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i <=m ; i++){
            for(int j = 0 ; j <= n ; j++){
                if( i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(s[i-1] == y[j-1]){
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return dp[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        return len(text1,text2,m,n);
    }
};
