class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()< 2)
        {
            return 0;
        }
        int minimum = INT_MAX,maximum = INT_MIN;
        int binnum = nums.size()-1;
        vector<int>minnum(binnum,INT_MAX);
        vector<int>maxnum(binnum,INT_MIN);
        for(int i = 0 ; i < nums.size(); i++){
            minimum = min(minimum,nums[i]);
            maximum = max(maximum,nums[i]);
        }
        float width = (maximum - minimum +0.0)/binnum;
        for(int i = 0; i < binnum+1; i++ ){
            if(nums[i] == minimum || nums[i] == maximum){
                continue;
            }

            int bin = (nums[i] - minimum)/width;
            minnum[bin] = min(minnum[bin],nums[i]);
            maxnum[bin] = max(maxnum[bin], nums[i]);
        }
        int ans = INT_MIN;
        int prev = minimum;
        for(int i = 0; i < binnum; i++){
            if(minnum[i] == INT_MAX){
                continue;
            }
            ans = max(ans,minnum[i] - prev);
            prev = maxnum[i];
        }
        return max(ans,maximum- prev);
    }
};
