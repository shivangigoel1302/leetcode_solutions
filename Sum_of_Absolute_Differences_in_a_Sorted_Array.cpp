class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        for(int i : nums){
            right += i;
        }
        vector<int>ans(n);
        for(int i = 0 ; i < n ; i++){
            right -= nums[i];
            int left_sum =abs( nums[i]*i - left);
            int right_sum = abs((n-i-1)*nums[i] - right);
            ans[i] = left_sum + right_sum;
            left += nums[i];
        }
        return ans;
    }
};
