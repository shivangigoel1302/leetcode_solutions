class Solution {
public:
    int mod;
    vector<vector<int>>dp;
    vector<vector<int>>prefdp;
    int pref(int n, int k){
        if(n < 2){
            return 0;
        }
        if(prefdp[n][k] != -1){
            return prefdp[n][k];
        }
        prefdp[n][k] = (lineseg(n,k)%mod + pref(n-1,k)%mod)%mod;
        return prefdp[n][k];
    }
    int lineseg(int n, int k){
        if(n < 2){
            return 0;
        }
        if(k == 1){
            return n*(n-1)/2;
        }
        if(k == n-1){
            return 1;
        }
        if(k >= n){
            return 0;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        long long temp =0;
        temp += lineseg(n-1,k);
        temp %= mod;
        temp += pref(n-1,k-1);
        temp %= mod;
        dp[n][k] = temp;
        return dp[n][k];
    }
    int numberOfSets(int n, int k) {
        mod = 1e9+7;
        dp.resize(n+1,vector<int>(n+1,-1));
        prefdp.resize(n+1,vector<int>(n+1,-1));
        return lineseg(n,k);
    }
};
