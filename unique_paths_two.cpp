class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[100][100]={0};
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(m==0||n==0)
        {
            return 0;
        }
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1)
        {
            return 0;
        }
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0&& obstacleGrid[i][j]!=1)
                {
                    if(j>=1)
                    {
                       dp[i][j]=dp[i][j-1];
                    }
                }
                else if(j==0&& obstacleGrid[i][j]!=1)
                {
                    if(i>=1)
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else
                {
                    if(obstacleGrid[i][j]!=1)
                    {
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
