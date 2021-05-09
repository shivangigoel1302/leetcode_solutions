class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag = 0;
        for(int i = nums.size() -1 ; i>0; i--){
            if(nums[i]>nums[i-1]){
                int minindex = i;
                int diff = INT_MAX;
                for(int k = i ; k < nums.size() ; k ++){
                    if(nums[k]-nums[i-1] < diff && nums[k]-nums[i-1] >0){
                        minindex = k ;
                    }
                }
               swap(nums[minindex],nums[i-1]);
                reverse(nums.begin()+i,nums.end());
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            reverse(nums.begin(),nums.end());
        }
    }
};
