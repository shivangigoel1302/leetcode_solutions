class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>v;
        int ans[nums.size()];
         ans[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
        int right=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            ans[i]=ans[i]*right;
            right=right*nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(ans[i]);
        }
        return v;
    }
};
