void subset(int i,vector<int>&v,vector<int>&nums, vector<vector<int>>&ans)
{
    if(i==nums.size())
    {
        ans.push_back(v);
        return;
    }
    v.push_back(nums[i]);
    subset(i+1,v,nums,ans);
    v.pop_back();
    subset(i+1,v,nums,ans);
}
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
           vector<int>v;
         vector<vector<int>>ans;
        subset(0,v,nums,ans);
        return ans;
    }
};
