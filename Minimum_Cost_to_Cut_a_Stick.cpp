class Solution {
public:
    int helper(vector<int>&cuts,int slen,int elen,int s,int e,vector<vector<int>>&dp){
        if(s > e){
            return 0;
        }
        if(dp[s][e] != -1){
            return dp[s][e];
        }
        int ans = INT_MAX;
        for(int i = s;i <= e; i++){
                ans = min(ans , elen-slen + helper(cuts,slen,cuts[i],s,i-1,dp) + helper(cuts,cuts[i],elen,i+1,e,dp));
        }

        return dp[s][e] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),-1));
        return helper(cuts,0,n,0,cuts.size()-1,dp);
    }
};
