class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto it: stones){
            sum += it;
        }
        int half = sum/2;
        vector<bool>dp(half + 1,false);
        dp[0] = true;
        int maxreach = 0;
        for(auto stone: stones){
            for(int i = half; i >= stone; i--){
                if(!dp[i]){
                     dp[i] = dp[i-stone];
                    if(dp[i]){
                        maxreach = max(maxreach,i);
                    }
                }

            }
        }
        return sum - 2*maxreach;
    }
};
