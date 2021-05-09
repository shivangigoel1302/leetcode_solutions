class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n+1];
        for(int i = 0 ; i < n+1 ; i++){
            dp[i] = 0;
        }
        dp[0] = 1;
        if(s[0] == '0'){
            dp[1] = 0;
        }
        else{
            dp[1] = 1;
        }
        for(int i = 2 ; i <= n ; i++){
            if(s[i-1] >= '1'){
                dp[i] = dp[i-1];
            }
            if(s[i-2] =='1' || (s[i-2] == '2' && s[i-1] <='6')){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
