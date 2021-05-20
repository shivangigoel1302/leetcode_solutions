class Solution {
public:
    void helper(vector<int>nums, int &sum, int i, int curr){
        if(i == nums.size()){
            sum += curr;
            return;
        }
        helper(nums,sum,i+1,curr);
        helper(nums,sum,i+1,curr^nums[i]);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        helper(nums,sum,0,0);
        return sum;
    }
};
