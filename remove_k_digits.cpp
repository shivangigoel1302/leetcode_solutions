class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        if(k==num.size())
        {
            return"0";
        }
        for(int i=0;i<num.size();i++)
        {
            while(k!=0&&!s.empty()&&s.top()>num[i])
            {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k--)
        {
            s.pop();
        }
        string ans="";
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        while(ans.size() > 1 && ans[0] == '0'){
            ans = ans.substr(1);
        }
        return ans;
    }
};
