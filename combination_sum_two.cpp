void combination(vector<int>&v,vector<vector<int>>&ans,int i,int target,vector<int>candidates, map<vector<int>,bool>&s)
{
    if(target==0)
    {
        if(s.find(v)==s.end())
        {
            ans.push_back(v);
            s[v]=true;
        }
        return;
    }
    if(target<0||i>=candidates.size())
    {
        return;
    }
    for(int j=i;j<candidates.size();j++)
    {
        v.push_back(candidates[j]);
        combination(v,ans,j+1,target-candidates[j],candidates,s);
        v.pop_back();
    }

}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        map<vector<int>,bool>s;
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        combination(v,ans,0,target,candidates,s);
        return ans;
    }
};
