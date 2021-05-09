class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<double>p(A.size()+1,0);
        int n = A.size();
        for(int i = 0 ; i < n; i++){
            p[i+1] = A[i] + p[i];
        }
        vector<double>dp(A.size());
        for(int i = 0 ; i < A.size(); i++){
            dp[i] = (p[n]-p[i])/(n-i);
        }
        for(int k = 0 ; k < K-1; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = i+1; j< n ; j++){
                    dp[i] = max(dp[i],(p[j]-p[i])/(j-i) + dp[j]);
                }
            }
        }
        return dp[0];
    }
};
