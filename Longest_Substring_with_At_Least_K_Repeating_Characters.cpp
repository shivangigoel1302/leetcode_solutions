class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size()==0||k>s.size())
        {
            return 0;
        }
        if(k==0)
        {
            return s.size();
        }
        map<char,int>m;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        int i=0;
        while(i<s.length()&&m[s[i]]>=k)
        {
            i++;
        }
        if(i==s.length())
        {
            return s.size();
        }
        int left=longestSubstring(s.substr(0,i),k);
        while(i+1<s.size()&&m[s[i]]<k)
        {
            i++;
        }
        int right=longestSubstring(s.substr(i),k);
        return max(left,right);
    }
};
