class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int p = -1;
        for(int i = 0 ; i < nums.size()-1; i++){
            if(nums[i]> nums[i+1]){
                if(p!= -1){
                    return false;
                }
                p = i;
            }
        }
        if(p==-1 || p == 0 || p == nums.size()-2 || nums[p-1] <= nums[p+1] || nums[p] <= nums[p+2]){
            return true;
        }
        return false;
    }
};
