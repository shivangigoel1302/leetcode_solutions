class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int>zero(strs.size(),0);
        vector<int>one(strs.size(),0);
        for(int i = 0 ; i < strs.size(); i++){
            for(auto c: strs[i]){
                if(c == '1')one[i]++;
            }
            zero[i] = strs[i].size()-one[i];
        }
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i = 0 ; i < strs.size(); i++){
            for(int j = m ; j >= zero[i]; j--){
                for(int k = n; k>=one[i]; k--){
                    dp[j][k] = max(dp[j][k], dp[j - zero[i]][k - one[i]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
