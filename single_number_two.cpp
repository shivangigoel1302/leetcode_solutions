class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>m;
       long int sum=0;
       long  int s=0;
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
        return (3*sum-s)/2;
    }
};
