class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        vector<vector<int>>dp(n,vector<int>(2000,0));
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                int diff = A[j] - A[i] + 1000;
                dp[i][diff] = max(2,dp[j][diff] +1);
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};
