class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[1000][1000]={0};
        dp[0][0]=grid[0][0];
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    if(j>=1)
                    {
                        dp[i][j]=dp[i][j-1]+grid[i][j];
                    }
                }
                else if(j==0)
                {
                    if(i>=1)
                    {
                        dp[i][j]=dp[i-1][j]+grid[i][j];
                    }
                }
                else
                {
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};
