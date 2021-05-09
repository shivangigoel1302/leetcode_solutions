class Solution {
public:
    string helper(int &i,string s)
    {
        if(i==s.size())
        {
            return"";
        }
        string word="";
        int num=0;
        for(;i<s.size();i++)
        {
             if(s[i]>='0'&&s[i]<='9')
        {
            num=num*10+s[i]-'0';
        }
        else if(s[i]=='[')
        {
            string ans=helper(++i,s);
            for(;num>0;num--)
            {
                word+=ans;
            }
        }
        else if(s[i]==']')
        {
            return word;
        }
            else
            {
                word+=s[i];
            }
        }
        return word;
    }
    string decodeString(string s) {
        int i=0;
        return helper(i,s);
    }
};
