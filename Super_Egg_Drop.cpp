class Solution {
public:

    int helper(int k,int n,vector<vector<int>>&dp){
        if(k == 1){
            return n;
        }
        if(n == 0 || n == 1){
            return n;
        }
        if(dp[k][n] != -1){
            return dp[k][n];
        }
        int ans = INT_MAX;
        int l = 1;
        int r = n;
        while(l <= r){
            int mid = (l+r)/2;
            int left = helper(k-1,mid-1,dp);
            int right = helper(k,n-mid,dp);
            ans = min(ans,max(left,right)+1);
            if(left < right){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }

        dp[k][n] = ans;
        return ans;
    }
    int superEggDrop(int k, int n) {

        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        for(int i = 1; i < k+1; i++){
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        for(int i = 1; i < n+1; i++){
            dp[1][i] = i;
        }
        return helper(k,n,dp);
    }
};
