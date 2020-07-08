class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int i=0;
        vector<string>words;
        string t="";
        while(i<str.length())
        {
             if(str[i]==' '){
                words.push_back(t);
                t="";
            }
            else
                t+=str[i];
            i++;
        }
        if(t.size()!=0)
        {
            words.push_back(t);
        }

        map<char,int>m;
        map<string,int>m2;
        if(words.size()!=pattern.size())
        {
            return false;
        }
        for(int i=0;i<words.size();i++)
        {
            if(m.find(pattern[i])==m.end())
            {
                m[pattern[i]]=i;
            }
            if(m2.find(words[i])==m2.end())
            {
                m2[words[i]]=i;
            }
            if(m[pattern[i]]!=m2[words[i]])
            {
                return false;
            }
        }
        return true;
    }
};
