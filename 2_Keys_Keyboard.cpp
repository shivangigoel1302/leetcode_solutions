class Solution {
public:
    int minSteps(int n) {
        vector<int>dp(n+1,INT_MAX);
        if(n == 1){
            return 0;
        }
        dp[0]= 0;
        dp[1] = 0;
        dp[2] = 2;
        for(int i = 3; i <=n ; i++){
            for(int j = 1; i - j >= j; j++){
                if((i-j)%j == 0){
                    int temp = 1 + (i-j)/j + dp[j];
                    dp[i] = min(dp[i],temp);
                }
            }
        }
        return dp[n];
    }
};
