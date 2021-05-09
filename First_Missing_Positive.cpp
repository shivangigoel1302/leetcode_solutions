class Solution {
public:
    int firstpositive(vector<int>&nums, int index){

        vector<int>v(nums.size()-index);
        for(int i = index; i < nums.size(); i++){
            v[i-index] = nums[i];
        }
        for(int i = 0;i < v.size(); i++){

            if(abs(v[i]) -1  < v.size() && v[abs(v[i]) -1] >0){
                v[abs(v[i]) - 1 ] = - v[abs(v[i])- 1 ];
            }

        }

        for(int j = 0; j < v.size(); j++){
            if(v[j] > 0){
                return j+1;
            }
        }
        return v.size()+1;
    }
    int segregate(vector<int>&nums){
        int j = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] <= 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return j;
    }
    int firstMissingPositive(vector<int>& nums) {
        int index = segregate(nums);
        return firstpositive(nums,index);
    }
};
