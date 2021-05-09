class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>>dp(d+1,vector<int>(target+1,0));
        dp[0][0] = 1;
        int mod = 1e9+7;
        for(int i = 1 ; i <=d; i++){
            for(int j = 1; j <= target; j++){
                long long int count = 0;
                for(int k = 1; k <= min(j,f); k++){
                    count = (count + dp[i-1][j-k])%mod;
                }
                dp[i][j] = count;
            }
        }
        return dp[d][target];
    }
};
