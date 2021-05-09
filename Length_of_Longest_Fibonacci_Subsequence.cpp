class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        vector<vector<int>>dp(n,vector<int>(n,2));
        map<int,int>m;
        for(int i= 0 ; i < n ; i++){
            m[A[i]] = i;
        }
        int ans = 0;
        for(int i  = 0 ; i < n ; i++){
            for(int j = i+1; j < n ; j++){
                if(m.find(A[j] - A[i]) != m.end()){
                    int k = m[A[j] -A[i]];
                    if(A[j] - A[i] >= A[i]) break;
                    dp[i][j] = dp[k][i] +1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
