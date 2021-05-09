class Solution {
public:
    int dp[500][500];
    int helper(int i , int j , vector<int>A, vector<int>B){
        if(i == A.size() || j == B.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(A[i] == B[j]){
            ans = max(ans, 1 + helper(i+1,j+1,A,B));
        }
        ans =max(ans,helper(i+1,j,A,B)) ;
        ans = max(ans,helper(i,j+1,A,B));
        return dp[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memset(dp,-1,sizeof(dp));
       return helper(0 , 0 , A, B);
    }
};
