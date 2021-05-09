class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n+1,0));
        for(int i = 0 ; i < m ; i++){
            dp[i][0] = 0;
            for(int j = 1; j<=n;j++){
                dp[i][j] += dp[i][j-1] + matrix[i][j-1];
            }
        }
        int ans = 0;
        for(int startcol = 1; startcol <= n ;startcol++){
            for(int endcol = startcol; endcol <=n ;endcol++){
                map<int,int>mp;
                int cursum = 0;
                mp[0] = 1;
                for(int row = 0 ; row < m; row++){
                    cursum += dp[row][endcol] - dp[row][startcol-1];
                    if(mp.find(cursum - target) != mp.end()){
                        ans += mp[cursum - target];
                    }
                    mp[cursum]++;
                }
            }
        }
        return ans;
    }
};
