class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
            {
                m[nums[i]]=1;
            }
            else
            {
                m[nums[i]]++;
            }
        }
        for(auto p:m)
        {
            if(p.second>nums.size()/2)
            {
                return p.first;
            }
        }
        return 0;
    }
};
