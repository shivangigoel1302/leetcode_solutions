class Solution {
public:
    string minWindow(string s, string t) {
        int hash_s[256]={0};
        int hash_t[256]={0};
        if(s.size()<t.size())
        {
            return "";
        }
        for(int i=0;i<t.size();i++)
        {
            hash_t[t[i]]+=1;
        }
        int start=0,count=0,startindex=-1,minlength=INT_MAX;
        for(int j=0;j<s.size();j++)
        {
            hash_s[s[j]]+=1;
            if(hash_s[s[j]]<=hash_t[s[j]]&&hash_t[s[j]]!=0)
            {
                count++;
            }
            if(count==t.size())
            {
                while(hash_s[s[start]]>hash_t[s[start]]||hash_t[s[start]]==0)
                {
                    if(hash_s[s[start]]>hash_t[s[start]])
                    {
                        hash_s[s[start]]-=1;
                    }
                    start+=1;
                }
                 int len_window=j-start+1;
            if(minlength>len_window)
            {
                minlength=len_window;
                startindex=start;
               }
            }
        }
        if(startindex==-1)
        {
            return "";
        }
        else
        {
            return s.substr(startindex,minlength);
        }
    }
};
