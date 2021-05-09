class Solution {
public:
    int helper(string s,int n){
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        vector<int>ans(n,0);
        for(int g = 0 ; g < n ; g++){
            for(int i = 0,j=g;j < n ; i++,j++){
                if(g==0){
                    dp[i][j] = true;
                }
                else if(g == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                }
                else{
                   if(s[i] == s[j] && dp[i+1][j-1]){
                       dp[i][j] = true;
                   }
                }
            }
        }

        for(int i = 1 ; i < n; i++){
            int minimum = INT_MAX;
            if(dp[0][i]){
                ans[i] = 0;
                continue;
            }
            for(int k =i; k>=1; k--){
                if(dp[k][i]){
                    minimum = min(minimum, ans[k-1] + 1);
                }
            }
            ans[i] = minimum;
        }
        //cout<<dp[0][n-1]<<" ";
        return ans[n-1];
    }
    int minCut(string s) {

     return helper(s,s.size());

    }
};
