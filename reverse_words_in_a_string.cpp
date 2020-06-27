class Solution {
public:
    string reverseWords(string s) {
        string str="";
        vector<string>ans;
        if(s.size()==0)
        {
            return s;
        }
       for(int i=0;i<s.size();i++)
       {
           if(s[i]!=' ')
           {
              if(i==s.size()-1)
              {
                  str+=s[i];
                  ans.push_back(str);
                  break;
              }
               str+=s[i];
           }
           else
           {
               if(str.size()>0)
               {
                   ans.push_back(str);
                   str="";
               }
           }
       }
        string final="";
        if(ans.size()==0)
        {
            return final;
        }
      for(int i=ans.size()-1;i>0;i--)
      {
          final+=ans[i];
          final+=" ";
      }
        final+=ans[0];
        return final;
    }
};
