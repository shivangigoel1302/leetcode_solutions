class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();)
        {
            if(nums[i]==target)
            {
                return i;
            }
            if(nums[i]>target)
            {
                return i;
            }
            i++;
        }
        return nums.size();
    }
};
