class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;

        int n = s.size();
        int st = 0 ;
        int end = 0;
        int maxlen = INT_MIN;

            for(int i = 0 ; i < n-1 ; i++){
                int l = i,r=i;
                while(l>=0 && r< n && s[l] == s[r]){
                    l--;
                    r++;
                    //st = l+1;
                }
                if(r-l-1 > maxlen){
                    st = l+1;
                    maxlen = r-l-1;
                }

            }


            for(int i = 0 ; i < n-1 ; i++){
                int l = i,r=i+1;
                while(l>=0 && r< n && s[l] == s[r]){
                    l--;
                    r++;
                   // st = l+1;
                }
                 if(r-l-1 > maxlen){
                    st = l+1;
                    maxlen = r-l-1;
                }
            }

        return s.substr(st,maxlen);
    }
};
