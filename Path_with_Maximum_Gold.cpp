class Solution {
public:

    int dfs(int i,int j,int n,int m,vector<vector<int>>& dp)
    {
        if(i<0||j<0||i>=n||j>=m)
            return 0;
        else if(dp[i][j]==0)
            return 0;
        else
        {
            int ans=dp[i][j];
            dp[i][j]=0;
            int a=dfs(i+1,j,n,m,dp);
            int b=dfs(i-1,j,n,m,dp);
            int c=dfs(i,j+1,n,m,dp);
            int d=dfs(i,j-1,n,m,dp);
            dp[i][j]=ans;
            return ans+max(max(a,b),max(c,d));
        }
    }

    int getMaximumGold(vector<vector<int>>& grid)
    {

        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              if(grid[i][j]!=0)
              {
                  ans=max(ans,dfs(i,j,n,m,grid));
              }
            }
        }

        return ans;

    }
};
