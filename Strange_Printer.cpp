class Solution {
public:
    int dp[101][101];
    int helper(string s, int l, int r){
        if( l > r){
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int count = helper(s,l+1,r)+1;
        for(int i = l+1; i <= r; i++){
            if(s[i] == s[l]){
                count = min(count,helper(s,l,i-1) + helper(s,i+1,r));
            }
        }
        dp[l][r] = count;
        return count;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(s,0,s.size()-1);
    }
};
