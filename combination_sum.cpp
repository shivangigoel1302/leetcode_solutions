
void sumadd(vector<int>&v,vector<int> candidates,int i,int target,vector<vector<int>>&ans)
{
    if(target<0||i>=candidates.size())
    {
        return;
    }
    if(target==0)
    {
        ans.push_back(v);
    }
    for(int j=i;j<candidates.size();j++)
    {
        v.push_back(candidates[j]);
       sumadd(v,candidates,j,target-candidates[j],ans);
        v.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        sumadd(v,candidates,0,target,ans);
        return ans;
    }
};
