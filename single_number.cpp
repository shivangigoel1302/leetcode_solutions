class Solution {
public:
    int singleNumber(vector<int>& nums) {
       map<int,int>m;
        int sum=0;
        int s=0;
       for(int i=0;i<nums.size();i++)
       {
           if(m.find(nums[i])==m.end())
           {
               m[nums[i]]=1;
           }
           s+=nums[i];
       }
        for(auto p:m)
        {
            sum+=p.first;
        }
        return 2*sum-s;
    }
};
