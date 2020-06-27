class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>dp(nums.size());
        vector<int>m(nums.size());

        if(nums.size()==1)
        {
            return nums[0];
        }
        dp[0]=nums[0];
        m[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=max(nums[i],max(nums[i]*dp[i-1],nums[i]*m[i-1]));
                m[i]=min(nums[i],min(nums[i]*dp[i-1],nums[i]*m[i-1]));
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
