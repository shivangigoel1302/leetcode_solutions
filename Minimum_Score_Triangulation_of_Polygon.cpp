class Solution {
public:
    int dp[105][105];
    int helper(vector<int>A,int i , int k){
        if( k < i+2){
            return 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        int minans = INT_MAX;
        for(int j = i+1; j < k ;j++){
            minans = min(minans,helper(A,i,j) + helper(A,j,k) + A[i]* A[j]* A[k]);
        }
        dp[i][k] = minans;
        return dp[i][k];
    }
    int minScoreTriangulation(vector<int>& A) {
        int i = 0;
        int k = A.size()-1;
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        ans = helper(A,i,k);
        return ans;
    }
};
