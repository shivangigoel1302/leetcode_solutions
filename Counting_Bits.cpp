class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        if(num == 0){
            return {0};
        }
        if(num == 1){
            return {0,1};
        }
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= num; i++){
            if(i%2 == 0){
                dp[i] = dp[i/2];
            }
            else{
                dp[i] = dp[i/2]+1;
            }
        }
        return dp;
    }
};
