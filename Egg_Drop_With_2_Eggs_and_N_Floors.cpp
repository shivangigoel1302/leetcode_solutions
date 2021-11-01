class Solution {
public:
    int floors(vector<vector<int>>&dp,int e,int f){
        if(dp[e][f] != -1){
            return dp[e][f];
        }
        if(f == 1){
            return 1;
        }
        if(e == 1){
            return f;
        }
        if(f == 0){
            return 0;
        }
        int ans = INT_MAX;
        for(int i = 1; i <= f; i++){
            ans = min(ans,max(floors(dp,e-1,i-1),floors(dp,e,f-i)));
        }
        return dp[e][f] = ans+1;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        for(int i = 0; i <= 2; i++){
            dp[i][1] = 1;
        }
        for(int i = 0; i <=n; i++){
            dp[1][i] = i;
        }
        return floors(dp,2,n);
    }
};
