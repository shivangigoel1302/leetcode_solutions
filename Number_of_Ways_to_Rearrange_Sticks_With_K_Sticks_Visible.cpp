class Solution {
public:
    int mod;
    long long helper(vector<vector<long long>>&dp,long long n, long long k){
        if(k == 0 || k > n){
            return 0;
        }
        if(n <= 2){
            return 1;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        long long temp = 0;
        temp = (temp + helper(dp,n-1,k-1))%mod;
        temp = (temp + (n-1) *helper(dp,n-1,k))%mod;
        temp %=mod;
        return dp[n][k] = temp;
    }
    int rearrangeSticks(int n, int k) {
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,-1));
        mod = 1e9+7;
        return helper(dp,n,k);
    }
};
