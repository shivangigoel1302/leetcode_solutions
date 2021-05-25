class Solution {
public:
    bool isMatch(string s, string p) {
        int i =0,j=0;
        int asterick = -1,match = -1;
        int n = p.size();
        int m = s.size();
        while(i < m){
            if(j < n && p[j] == '*'){
                match = i;
                asterick = j++;
            }
            else if(j < n && (s[i] == p[j] || p[j] == '?')){
                i++;
                j++;
            }
            else if(asterick >= 0){
                i = match+1;
                match++;
                j = asterick +1;
            }
            else{
                return false;
            }
        }
        while(j < n){
            if(p[j] != '*'){
                return false;
            }
            j++;
        }
        return true;
    }
};
