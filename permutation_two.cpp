void permute(vector<vector<int>>&ans,vector<int>nums,int i,map<vector<int>,bool>&m)
{
    if(i==nums.size())
    {
        if(m.find(nums)==m.end())
        {
            ans.push_back(nums);
            m[nums]=true;
        }
        return;
    }
    for(int j=i;j<nums.size();j++)
    {
        swap(nums[i],nums[j]);
        permute(ans,nums,i+1,m);
    }
}
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        map<vector<int>,bool>m;
        permute(ans,nums,0,m);
        return ans;
    }
};
