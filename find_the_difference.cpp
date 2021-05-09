class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(m.find(t[i])==m.end()||m[t[i]]==0)
            {
                return t[i];
            }
            else
            {
                m[t[i]]--;
            }
        }
        return 'a';
    }
};
