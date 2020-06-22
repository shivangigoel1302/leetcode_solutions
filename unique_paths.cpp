int robo(int m,int n)
{
    int dp[100][100]={0};
    for(int k=0;k<n;k++)
    {
        for(int p=0;p<m;p++)
        {
            if(k==0)
            {
                dp[k][p]=1;
            }
            else if(p==0)
            {
                dp[k][p]=1;
            }
            else
            {
                dp[k][p]=dp[k][p-1]+dp[k-1][p];
            }
        }
    }

    return dp[n-1][m-1];


}
class Solution {
public:
    int uniquePaths(int m, int n) {
      int c=robo(m,n);
        return c;
    }
};
