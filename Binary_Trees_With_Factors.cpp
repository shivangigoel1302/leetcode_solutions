class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        map<int,int>m;
        int MOD = 1000000007;
        vector<long long>dp(A.size(),1);
        sort(A.begin(),A.end());
        int ans = 0;
        for(int i = 0 ; i < A.size(); i++){
            for(int j = 0 ; j < i ; j++){
                if(A[i] % A[j] == 0){
                    if(m.find(A[i]/A[j]) != m.end()){
                            dp[i] = (dp[i]+dp[j]*m[A[i]/A[j]])%MOD;
                    }
                }
            }
           // cout<<dp[i]<<" ";
            m[A[i]] = dp[i]%MOD;
            ans = (ans +dp[i])%MOD;
        }
        return ans%MOD;
    }
};
