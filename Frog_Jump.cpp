class Solution {
public:
    unordered_map<int, bool> dp;
    bool helper(vector<int>& stones,int i, int k){
        int key = i | k << 11;
        // since the maximum value of k could be 2000 and the the values of 2^11 is 2048 it is safe to combine i and k
        // k starts with 0 and 1 therefore maximum val of k could be the number of stones
        if(dp.count(key) > 0){
            return dp[key];
        }
        for(int j = i+1; j < stones.size(); j++){
            int gap = stones[j] - stones[i];
            if(gap < k-1){
                continue;
            }
            if(gap > k+1){
                return dp[key] = false;
            }
            if(helper(stones,j,gap)){
                dp[key]= true;
                return true;
            }
        }
        return dp[key] = (i == stones.size()-1);
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        return helper(stones,0,0);
    }
};

