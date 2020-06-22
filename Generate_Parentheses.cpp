
void helper(vector<string>&v,string s,int lc,int rc,int n)
{
    if(s.length()==2*n)
    {

           v.push_back(s);


        return;
    }
    if(lc<n)
    {
        helper(v,s+"(",lc+1,rc,n);
    }
    if(rc<lc)
    {
        helper(v,s+")",lc,rc+1,n);
    }
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>v;

        helper(v,"",0,0,n);
        return v;
    }
};
