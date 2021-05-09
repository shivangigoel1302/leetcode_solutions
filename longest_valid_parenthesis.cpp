class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int>dp(s.size(),0);
        int ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '('){
                continue;
            }
            if(s[i] == ')'){
                if(i >=2 && s[i-1] == '('){
                    dp[i] = dp[i-2]+2;
                }
                else if(i >=1 &&s[i-1] == '(' ){
                    dp[i] = 2;
                }
                else{
                    if(i >0 && i - dp[i-1] >0 && s[i-dp[i-1]-1] == '('){
                       if(i-dp[i-1]-2 >=0){
                           dp[i] = dp[i-1] + dp[i-dp[i-1] - 2]+2;
                       }
                        else{
                            dp[i]= 2 + dp[i-1];
                        }
                    }
                    else{

                        continue;
                    }
                }
            }
            //cout<<dp[i]<<" ";
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
