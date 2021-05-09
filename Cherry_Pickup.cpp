class Solution {
public:
    int dp[51][51][51];
    int helper(vector<vector<int>>&grid,int i,int j,int k,int n){
        int l = i+j-k;
        if(i < 0 || i >=n || j < 0 || j>=n || k <0 ||  k>=n || l< 0 || l >=n
           || grid[i][j] == -1 || grid[l][k] == -1){
            return INT_MIN;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        if(i == n-1 && j == n-1){
            return grid[i][j];
        }
        int ans = grid[i][j];
        if(i != l){
            ans += grid[l][k];
        }
        int temp = max(helper(grid,i,j+1,k+1,n),helper(grid,i,j+1,k,n));
         temp = max(temp,helper(grid,i+1,j,k+1,n));
         temp = max(temp,helper(grid,i+1,j,k,n));
        ans += temp;
        return dp[i][j][k]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        memset(dp,-1,sizeof(dp));
        return max(0,helper(grid,0,0,0,n));
    }
};
