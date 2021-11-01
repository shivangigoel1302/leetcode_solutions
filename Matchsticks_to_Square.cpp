class Solution {
public:
    vector<vector<int>>dp;
    bool helper(vector<int>&matchsticks,int mask,int sides,int &target){
       int used = 0;
        for(int i = matchsticks.size()-1; i >= 0; i--){
            if((mask &(1 << i))==0){
                used += matchsticks[matchsticks.size()-i-1];
            }
        }
        if(used > 0 && used%target == 0){
            sides++;
        }
        if(sides == 3){
            return true;
        }
        if(dp[mask][sides] != -1){
            return dp[mask][sides];
        }
        int c = (used/target) + 1;
        int rem = c*target - used;
        for(int i = matchsticks.size()-1; i>= 0; i--){
            if(matchsticks[matchsticks.size()-i-1] <= rem && (mask & (1 << i))){
                if(helper(matchsticks,mask^(1<<i),sides,target)){
                    return dp[mask][sides] = true;
                }
            }
        }
        return dp[mask][sides] = false;

    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(int i = 0; i < matchsticks.size(); i++){
            sum += matchsticks[i];
        }
        int target = sum/4;
        if(target* 4 != sum){
            return false;
        }

        dp.resize(1<<15,vector<int>(4,-1));
        // memeset(dp,-1,sizeof(dp));
        int l = matchsticks.size();
        int sides = 0;
        return helper(matchsticks,(1<<l)-1,sides,target);
    }
};
