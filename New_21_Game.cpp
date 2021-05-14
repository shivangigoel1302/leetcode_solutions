class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>dp(n+1,0);
        dp[0] = 1.0;
        double window = 0.0;
        for(int i = 1; i < n+1; i++){
            if(i-1 < k){
                window += dp[i-1];
            }
            if(i-maxPts - 1 >= 0 && window){
                window -= dp[i-maxPts - 1];
            }
            dp[i] = 1.0/maxPts*(window);
        }
        double ans = 0;
        for(int i = k; i <=n ; i++){
            ans += dp[i];
        }
        return ans;
    }
};
