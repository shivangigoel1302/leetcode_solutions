class Solution {
public:
    int helper(string &s,int i,int j,vector<vector<int>>&dp){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = INT_MAX;
        if(s[i] == s[j]){
            return helper(s,i+1,j-1,dp);
        }
        ans = 1+ min(helper(s,i+1,j,dp),helper(s,i,j-1,dp));
        return dp[i][j] = ans;
    }
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return helper(s,0,s.size()-1,dp);
    }
};
