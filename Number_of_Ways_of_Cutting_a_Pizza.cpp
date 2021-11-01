class Solution {
public:
    int dp[51][51][11];
    int mod;
    bool hasapple(int sr,int er,int sc,int ec,vector<vector<int>>&apples){
        int a = apples[er][ec];
        if(sr > 0){
            a -= apples[sr-1][ec];
        }
        if(sc > 0){
            a -= apples[er][sc-1];
        }
        if(sr > 0 && sc > 0){
             a += apples[sr-1][sc-1];
        }
        return a > 0;
    }
    int helper(vector<vector<int>>&apples,int cut,int r,int c){
        if(cut == 0){
            return 1;
        }
        if(dp[r][c][cut] != -1){
            return dp[r][c][cut];
        }
        int ans = 0;
        for(int i = r; i < apples.size()-1; i++){
            if(hasapple(r,i,c,apples[r].size()-1,apples) && hasapple(i+1,apples.size()-1,c,apples[0].size()-1,apples)){
                ans += helper(apples,cut-1,i+1,c);
                ans %= mod;
            }
        }
        for(int j = c; j < apples[0].size()-1; j++){
            if(hasapple(r,apples.size()-1,c,j,apples) && hasapple(r,apples.size()-1,j+1,apples[0].size()-1,apples)){
                ans += helper(apples,cut-1,r,j+1);
                ans %= mod;
            }
        }
        // cout<<ans<<","<<r<<" "<<c<<endl;
        return dp[r][c][cut] = ans%mod;
    }
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        memset(dp,-1,sizeof(dp));
        mod  = 1e9+7;
        vector<vector<int>>apples(m,vector<int>(n,0));
        if(pizza[0][0] == 'A'){
            apples[0][0] = 1;
        }
        for(int i = 1;i < m ; i++){
            apples[i][0] += apples[i-1][0];
            if(pizza[i][0] == 'A'){
                apples[i][0]++;
            }
        }
        for(int i = 1; i < n; i++){
            apples[0][i] += apples[0][i-1];
            if(pizza[0][i] == 'A'){
                apples[0][i]++;
            }
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(pizza[i][j] == 'A'){
                    apples[i][j] = 1;
                }
                apples[i][j] += apples[i-1][j] + apples[i][j-1] - apples[i-1][j-1];

            }

        }

        return helper(apples,k-1,0,0);
    }
};
