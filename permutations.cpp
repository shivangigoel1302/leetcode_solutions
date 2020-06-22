void permutations(vector<vector<int>>&ans,int i,vector<int>nums)
{
    if(i==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int j=i;j<nums.size();j++)
    {
        swap(nums[i],nums[j]);
        permutations(ans,i+1,nums);
    }
}
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;
        permutations(ans,0,nums);
        return ans;
    }
};
