class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int length = 0 ;
        int i = 0 ;
        int count = 0;
        while(i < nums.size()){
            int j = i;
            if(nums[i] == 1){
                while(j < nums.size() && nums[j] == 1 ){
                    j++;
                    length++;
                }
                count = max(count,length);
                length = 0;
                i = j;
            }
            else{
                i++;
            }
        }
        return count;
    }
};
