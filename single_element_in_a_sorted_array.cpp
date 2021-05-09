class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       if(nums.size()<1){
           return -1;
       }
        if(nums.size() == 1){
           return nums[0];
       }
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = (s+e)/2;
            if(mid == 0){
                if(nums[mid] != nums[mid+1] ){
                    return nums[mid];
                }
            }
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                return nums[mid];
            }
            if(mid%2==0){
                if(nums[mid] == nums[mid+1]){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
            else{
                 if(nums[mid] == nums[mid+1]){
                    e = mid-1;

                }
                else{
                   s = mid+1;
                }
            }
        }
        return -1;
    }
};
