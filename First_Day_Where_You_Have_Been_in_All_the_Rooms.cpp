class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        int n = nextVisit.size();
        int mod = 1e9+7;
        vector<long long>dp(n,0);
        for(int i = 1; i < n; i++){
            if(nextVisit[i-1] == i-1){
                dp[i] = dp[i-1] + 2;
            }
            else{
                dp[i] = (1 + dp[i-1] - dp[nextVisit[i-1]] + dp[i-1] +1 + mod)%mod;
            }
        }
        return dp[n-1]%mod;
    }
};
