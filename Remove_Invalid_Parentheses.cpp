class Solution {
public:
    int minimum(string s){
        int n=s.length();
        stack<char>stk;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                stk.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(stk.empty())
                {
                    stk.push(s[i]);
                }
                else
                {
                    if(stk.top()=='(')
                    {
                        stk.pop();
                    }
                    else
                    {
                        stk.push(s[i]);
                    }
                }
            }
        }
        return stk.size();
    }
    void helper(vector<string>&ans, unordered_set<string>&dict,unordered_set<string>&st,string s,int req){
        if(req == 0){
            if(minimum(s) == 0 && st.find(s) == st.end()){
                ans.push_back(s);
                st.insert(s);
            }
            return;
        }
        for(int i = 0 ; i < s.size(); i++){
            string temp = s.substr(0,i) + s.substr(i+1);
            if(dict.find(temp) == dict.end()){
                dict.insert(temp);
                helper(ans,dict,st,temp,req-1);
            }
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
       int req = minimum(s);
        unordered_set<string>dict,st;
        vector<string>ans;
        helper(ans,dict,st,s,req);
        return ans;
    }
};
