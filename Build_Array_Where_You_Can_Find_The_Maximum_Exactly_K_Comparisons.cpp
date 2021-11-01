class Solution {
public:
    int dp[51][51][101];
    int n,m,k;
    int mod;
    int count(int curr,int len,int lar){
        if(curr == n){
            if(len == k){
                return 1;
            }
            return 0;
        }
        if(dp[curr][len][lar] != -1){
            return dp[curr][len][lar];
        }
        int ans = 0;
        for(int i = 1; i <= m; i++){
            if(i > lar){
                ans += count(curr+1,len+1,i);
            }
            else{
                ans += count(curr+1,len,lar);
            }
            ans = ans%mod;
        }
        return dp[curr][len][lar] = ans;
    }
    int numOfArrays(int N, int M, int K) {
        n = N;
        m = M;
        k = K;
        mod = 1e9+7;
        memset(dp,-1,sizeof(dp));
        return count(0,0,0);
    }
};
