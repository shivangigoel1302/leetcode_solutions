class Solution {
public:
    int longestPalindrome(string s) {
       map<char,int>m;
        int count=0;
        int length=0;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
       bool isodd=false;
        for(auto i:m)
        {
            if(i.second%2==0)
            {
                count+=i.second;
            }
            else if(i.second%2!=0)
            {
               count+=i.second-1;
                isodd=true;
            }
        }
        if(isodd) count+=1;
        return count;

    }
};
