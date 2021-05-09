class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        int i = 2;
        int j = 2;
        while(i < nums.size()){
            if(nums[i] != nums[j-1] || nums[i] !=nums[j-2]){
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }
        return j;
    }
};
