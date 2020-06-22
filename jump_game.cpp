class Solution {
public:
    bool canJump(vector<int>& nums) {
      if(nums.size()==1||nums.size()==0)
      {
          return true;
      }
        int curr=nums[0];
    for(int i=0;i<=curr;i++)
    {
        if(curr>=nums.size()-1)
        {
            return true;
        }
        curr=max(curr,nums[i]+i);
      }
        return false;
    }
};
