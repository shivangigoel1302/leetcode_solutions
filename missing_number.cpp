class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int mustbe=nums.size()*(nums.size()+1)/2;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=nums[i];
        }
        return mustbe-ans;
    }
};
