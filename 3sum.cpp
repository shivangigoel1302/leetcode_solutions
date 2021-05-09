class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>res;
        sort(nums.begin(),nums.end());
        int i,k,j;
        int n=nums.size();
        for(i=0;i<n-2;i++)
        {
            j=i+1;
            k=n-1;
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0)
                {
                    vector<int>tmp(3);
                    tmp[0]=nums[i];
                    tmp[1]=nums[j];
                    tmp[2]=nums[k];

                    res.insert(tmp);
                    j++;
                    k--;
                }
                else if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }

            }
        }
        vector<vector<int>>result(res.begin(),res.end());
        return result;

    }
};
