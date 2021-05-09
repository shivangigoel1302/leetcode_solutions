class Solution {
public:
    int getans(vector<vector<int>>costs,int c1,int c2,int n,vector<vector<int>>&dp){
        if(c1 + c2 == 2*n || c1>n || c2 >n){
            return 0;
        }
        if(dp[c1][c2] != -1) return dp[c1][c2];
        int ans = INT_MAX;
        if(c1 < n){
            ans = min(ans,getans(costs,c1+1,c2,n,dp) + costs[c1+c2][0] );
        }
        if(c2 < n){
            ans = min(ans,getans(costs,c1,c2+1,n,dp) + costs[c1+c2][1]);
        }
        return dp[c1][c2] = ans;
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = getans(costs,0,0,n,dp);
        return ans;

    }
};
