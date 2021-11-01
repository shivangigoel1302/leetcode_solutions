class Solution {
public:
    int dp[501][501];
    int mod;
    int helper(int pick,int drop){
       long long int opt1 = 0;
       long long int opt2 = 0;
        if(dp[pick][drop] != -1){
            return dp[pick][drop];
        }
        if(pick > 0){
            opt1=pick;
            opt1*= helper(pick-1,drop+1);
            opt1%=mod;
        }
        if(drop){
            opt2 = drop;
            opt2 *= helper(pick,drop-1);
            opt2%=mod;
        }
        return dp[pick][drop] = opt1 + opt2 == 0 ? 1: (opt1+opt2)%mod;
    }
    int countOrders(int n) {
        int pick = n;
        int drop = 0;
        mod = 1e9+7;
        memset(dp,-1,sizeof(dp));
        return helper(pick,drop);
        //   int dp[501];
        // dp[0]=0;dp[1]=1;dp[2]=6;
        // for(int i=3;i<=n;i++){
        //     int sm=((2*i-1)*(2*i-1+1)/2)%mod;
        //     dp[i]=((long)dp[i-1]*sm)%mod;
        // }
        // return dp[n];
    }
};
