class Solution {
public:
    vector<int>getminimum(vector<vector<int>>&grid,int i,int n){
        vector<int>dp(n,INT_MAX);
        vector<int>right(n,INT_MAX);
        for(int j = 1; j < n; j++){
            dp[j] = min(dp[j],min(dp[j-1],grid[i][j-1]));
        }
        for(int j = n-2; j >= 0; j--){
            right[j] = min(right[j],min(right[j+1],grid[i][j+1]));
        }
        for(int j = 0; j < n; j++){
            dp[j] = min(dp[j],right[j]);
        }
        return dp;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = m-2; i >= 0; i--){
            vector<int>dp = getminimum(grid,i+1,n);
            for(int j = 0; j < n; j++){
                grid[i][j] += dp[j];
            }
        }
         int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans,grid[0][i]);
        }
        return ans;
    }

};
