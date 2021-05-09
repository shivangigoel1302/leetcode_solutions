class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        for(int i = 0 ; i < nums.size(); i++){
            sum = max(sum + nums[i], 0);
            maxsum = max(maxsum, abs(sum));
        }
        int nsum = 0;
        int minsum = INT_MAX;
        for(int i = 0 ; i < nums.size(); i++){
            nsum = min(nsum + nums[i],0);
            minsum = min(minsum, nsum);
        }
        return max(abs(minsum),abs(maxsum));
    }
};
