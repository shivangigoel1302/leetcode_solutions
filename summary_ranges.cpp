class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int lb=0;
        int ub=1;
        vector<string>v;
        if(nums.size()==0)
        {
            return v;
        }
        if(nums.size()==1)
        {
            v.push_back(to_string(nums[0]));
            return v;
        }
        while(lb<nums.size()&&ub<nums.size())
        {
            while(ub<nums.size()&&nums[ub]-1==nums[ub-1])
            {
                ub++;
            }
            if(ub==lb+1&&nums[ub]-1!=nums[ub-1])
            {
                v.push_back(to_string(nums[lb]));
            }
            else
            {

             string str=to_string(nums[lb])+"->"+to_string(nums[ub-1]);
            v.push_back(str);
            }
             if(ub==nums.size())
            {
                break;
            }
            lb=ub;
            ub++;
        }
        if(lb==nums.size()-1)
        {
            v.push_back(to_string(nums[nums.size()-1]));
        }
        return v;
    }
};
