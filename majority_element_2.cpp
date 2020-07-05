class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int first=INT_MAX;
        int second=INT_MAX;
        int count1=0;
        int count2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==first)
            {
                count1++;
            }
            else if(nums[i]==second)
            {
                count2++;
            }
            else if(count1==0)
            {
                count1++;
                first=nums[i];
            }
            else if(count2==0)
            {
                count2++;
                second=nums[i];
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==first)
            {
                count1++;
            }
            else if(nums[i]==second)
            {
                count2++;
            }
        }
        if(count1>nums.size()/3)
        {
            ans.push_back(first);
        }
        if(count2>nums.size()/3)
        {
            ans.push_back(second);
        }
        return ans;
    }
};
