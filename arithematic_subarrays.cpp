class Solution {
public:
    bool isValid(int i, int r, vector<int> nums){
        sort(nums.begin() +i,nums.begin()+r+1);
        int difference = nums[i+1] - nums[i];
        for(int start = i+1 ; start<=r ; start++){
            if(nums[start] - nums[start-1] != difference){
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>v;
        for(int i = 0 ; i < l.size(); i++){
            if(isValid(l[i],r[i],nums)){
                v.push_back(true);
            }
            else{
                v.push_back(false);
            }
        }
        return v;
    }
};
