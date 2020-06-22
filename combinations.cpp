void backtrack(int i,int n,int k,vector<int>&v,vector<vector<int>>&ans)
{
    if(i>n)
    {
        if(v.size()==k)
        {
            ans.push_back(v);
        }
        return;
    }
    if(v.size()==k)
    {
        ans.push_back(v);
        return;
    }
   v.push_back(i);
    backtrack(i+1,n,k,v,ans);
    v.pop_back();
    backtrack(i+1,n,k,v,ans);
}
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
          vector<vector<int>>ans;
        vector<int>v;
        if(n==1)
        {
            v.push_back(1);
            ans.push_back(v);
            return ans;
        }
        if(k==1)
        {
            int i=1;
            while(i<=n)
            {
                v.push_back(i);
                ans.push_back(v);
                v.pop_back();
                i++;
            }
            return ans;
        }
        backtrack(1,n,k,v,ans);
        return ans;
    }
};
