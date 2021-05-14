class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i = 0; i < s2.size();i++){
            int a = (int)s2[i];
            dp[0][i+1] = dp[0][i] + a;
        }
        for(int i = 0; i < s1.size(); i++){
            int a = (int)s1[i];
            dp[i+1][0] = dp[i][0] + a;
        }
        for(int i = 1; i < s1.size()+1;i++){
            for(int j = 1; j < s2.size()+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int x = (int)s1[i-1];
                    int y = (int)s2[j-1];
                    int a = dp[i-1][j] + x;
                    int b = dp[i][j-1] + y;
                    dp[i][j] = min(a,b);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
