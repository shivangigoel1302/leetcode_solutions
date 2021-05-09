class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
        vector<int>dp(s.size(),0);
        dp[s.size()-1] = (s[s.size()-1]) -'0';
        for(int i = s.size()-2; i >=0 ;i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i+1] + 1;
            }
        }
        long long ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};
