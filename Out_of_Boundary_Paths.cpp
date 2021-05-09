class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int mod  = 1e9 + 7;
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[i][j] = 1;
        int count =  0;
        for(int move = 1; move<= N; move++){
            vector<vector<int>>temp(m,vector<int>(n,0));
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(i == 0){
                        count = (count + dp[i][j])%mod;
                    }
                    if(i == m-1){
                        count = (count + dp[i][j])%mod;
                    }
                    if(j == 0){
                        count = (count + dp[i][j])%mod;
                    }
                    if(j == n-1){
                        count = (count + dp[i][j])%mod;
                    }
                    temp[i][j] = (((i>0 ? dp[i-1][j] : 0)%mod + (i < m-1 ? dp[i+1][j]:0)%mod)%mod + ((j > 0?dp[i][j-1]:0)%mod + (j < n-1 ?dp[i][j+1]:0)%mod)%mod)%mod;
                }
            }
            dp = temp;
        }
        return count;
    }
};
