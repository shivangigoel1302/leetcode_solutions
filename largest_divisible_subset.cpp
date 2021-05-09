class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
         vector<int>ans;
        if(nums.size()==0)
        {
            return ans;
        }
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int maxlen=*max_element(dp.begin(),dp.end());
        int prev=-1;
        for(int i=dp.size()-1;i>=0;i--)
        {
            if(dp[i]==maxlen&&(prev==-1||prev%nums[i]==0))
            {
                ans.push_back(nums[i]);
                maxlen--;
                prev=nums[i];
            }
        }
        return ans;
    }
};
