class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        if(A.size() < 1){
            return A.size();
        }
        unordered_map<long long,int>dp[n];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                long long d = (long long)A[i] - (long long)A[j];
                dp[i][d] += dp[j][d] + 1;
                ans += dp[j][d];
            }
        }
        return ans;
    }
};
