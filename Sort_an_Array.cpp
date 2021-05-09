class Solution {
public:
    int pivot(vector<int>&nums,int s , int e){
        int key = nums[e];
        int j = s-1;
        for(int i = s ; i < e ; i++){
            if(nums[i] <= key){
                j++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[j+1],nums[e]);
        return j+1;
    }
    void quicksort(vector<int>&nums, int s, int e){
        if(s > e){
            return;
        }
        int p = pivot(nums,s,e);
        quicksort(nums,s,p-1);
        quicksort(nums,p+1,e);
    }
    vector<int> sortArray(vector<int>& nums) {

        quicksort(nums,0,nums.size()-1);

        return nums;
    }
};
