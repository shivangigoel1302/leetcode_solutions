class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        if(nums.size()==0)
        {
            return v;
        }
        if(nums.size()==1)
        {
            if(nums[0]==target)
            {
                v.push_back(nums[0]);
                return v;
            }
            else
            {
                return v;
            }
        }
        int l=0;

        int r=nums.size()-1;
        while(l<r)
        {
            int sum=nums[l]+nums[r];
            if(sum<target)
            {
                l++;
            }
            else if(sum>target)
            {
                r--;
            }
            else{
                v.push_back(l+1);
                v.push_back(r+1);
                break;
            }
        }
        return v;
    }
};
