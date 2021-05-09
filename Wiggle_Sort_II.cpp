class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>val(nums.begin(),nums.end());
        sort(val.begin(),val.end());
        int k = val.size()-1;
        for(int i = 1; i< nums.size(); i+=2){
            nums[i] = val[k--];
        }

        for(int i = 0 ; i < nums.size(); i+=2){
            nums[i] = val[k--];
        }
        return;
    }
};
