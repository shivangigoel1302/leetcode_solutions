class Solution {
public:
    bool ispossible(vector<int>nums,int k,int n)
    {
       bool subset[n+1][k+1];
        for(int i=0;i<=n;i++)
        {
            subset[i][0]=true;

        }
        for(int i=1;i<=k;i++)
        {
            subset[0][i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(nums[i-1]>j)
                {
                    subset[i][j]=subset[i-1][j];
                }
                else if(nums[i-1]<=j)
                {
                    subset[i][j]=subset[i-1][j]||subset[i-1][j-nums[i-1]];
                }
            }
        }
        return subset[n][k];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
        {
            return false;
        }
        else
        {
            if (ispossible(nums,sum/2,nums.size()))
            {
                return true;
            }
            return false;
        }
    }
};
