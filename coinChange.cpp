class Solution {
public:
    int coinhelper(vector<int>&coins, int amount, int dp[]){
        if(amount == 0){
            dp[amount] = 0;
            return 0;
        }
        if(dp[amount]!= -1){
            return dp[amount];
        }
        int ans = INT_MAX;
        int smallans = INT_MAX;
        for(int i = 0 ; i < coins.size(); i++){
            if(amount>=coins[i]){
                smallans= coinhelper(coins,amount-coins[i],dp);
            }
            if(smallans!=INT_MAX){
                ans = min(smallans+1,ans);
            }
        }
        dp[amount] = ans;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int dp[100000]={-1};
        for(int i = 0 ; i < amount+1; i++){
            dp[i] = -1;
        }
        int result = coinhelper(coins,amount,dp);
        if(result == INT_MAX){
            return -1;
        }
        return result;
    }
};
