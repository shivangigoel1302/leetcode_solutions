class Solution {
public:
    int changestate(int state){
        if(state == 1) return 0;
        return 1;
    }
    int minFlips(string target) {
        int state = 0;
    vector<int>dp(target.size(),0);
        for(int i = 0 ; i < target.size(); i++){
            if(target[i] != state+'0'){
                if(i == 0){
                    dp[i] = 1;
                    state = changestate(state);
                    continue;
                }
                dp[i] = dp[i-1] + 1;
                state = changestate(state);
            }
            else{
                if(i >0){
                    dp[i] = dp[i-1];
                }
            }

        }
        return dp[target.size()-1];
    }
};
