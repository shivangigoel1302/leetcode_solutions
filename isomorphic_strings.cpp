class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>m;
        map<char,char>mp;
        for(int i=0;i<s.size();i++)
        {

                if(m.find(s[i])==m.end())
                {
                    m[s[i]]=t[i];
                }
                else
                {
                    if(m[s[i]]!=t[i])
                    {
                        return false;
                    }
                }

        }
        for(int i=0;i<t.size();i++)
        {
            if(mp.find(t[i])==mp.end())
                {
                   mp[t[i]]=s[i];
                }
              else
                {
                    if(mp[t[i]]!=s[i])
                    {
                        return false;
                    }
                }

        }
        return true;
    }
};
