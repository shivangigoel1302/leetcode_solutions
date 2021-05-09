class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";
        while(a!=0 || b!=0){
            char touse = 'b';
            if(s.size() >= 2 && s[s.size()-1] == s[s.size()-2]){
                if(s[s.size()-1] == 'b'){
                    touse = 'a';
                }
            }
            else{
                if(a >= b){
                    touse = 'a';
                }
            }
            if(touse == 'a'){
                s+= 'a';
                a--;
            }
            else{
                 s+= 'b';
                b--;
            }

        }
        return s;
    }
};
