class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1){
            return 0;
        }
        int left = 0;
        int right =0,prod=1;
        int n = nums.size();
        int ans = 0;
        while(right < n){
            prod *=nums[right];
            while(prod >= k){
                prod/=nums[left];
                left++;
            }
            ans += right-left+1;
            right++;
        }
        return ans;
    }
};
