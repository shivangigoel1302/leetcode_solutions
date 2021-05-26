class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool>dp(s.size(),false);
        dp[0] = true;
        int count = 0;
        for(int i = 1; i < s.size(); i++){
            if(i > maxJump){
                count -= dp[i - maxJump-1];
            }
            if(i >= minJump){
                count += dp[i-minJump];
            }
            if(s[i] == '0' && count){
                dp[i]= true;
            }
            else{
                dp[i] = false;
            }
        }
        return dp[s.size()-1];
    }
};
