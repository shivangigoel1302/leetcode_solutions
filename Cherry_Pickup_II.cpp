class Solution {
public:
    int dp[71][71][71];
    int helper(vector<vector<int>>&grid,int r,int c1,int c2){
       if(r >= grid.size() || c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()){
           return 0;
       }
        int ans = grid[r][c1] + grid[r][c2];
        if(c1 == c2){
            ans -= grid[r][c1];
        }
        if(dp[r][c1][c2] != -1){
            return dp[r][c1][c2];
        }
        int curr = INT_MIN;
        curr = max(curr,ans + helper(grid,r+1,c1,c2));
        curr = max(curr,ans + helper(grid,r+1,c1+1,c2));
        curr = max(curr,ans + helper(grid,r+1,c1-1,c2));
        curr = max(curr,ans + helper(grid,r+1,c1,c2+1));
        curr = max(curr,ans + helper(grid,r+1,c1+1,c2+1));
        curr = max(curr,ans + helper(grid,r+1,c1-1,c2+1));
        curr = max(curr,ans + helper(grid,r+1,c1,c2-1));
        curr = max(curr,ans + helper(grid,r+1,c1+1,c2-1));
        curr = max(curr,ans + helper(grid,r+1,c1-1,c2-1));
        return dp[r][c1][c2] = curr;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return max(0,helper(grid,0,0,m-1));
    }
};
