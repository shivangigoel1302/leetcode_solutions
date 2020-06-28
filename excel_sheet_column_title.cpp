class Solution {
public:
    string convertToTitle(int n) {
       string s="";
        while(n>0)
        {
            if(n%26==0)
            {
                s+=(char(90));
                n=(n-26)/26;
            }
            else
            {
                s+=char(n%26+64);
                n=n/26;
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
