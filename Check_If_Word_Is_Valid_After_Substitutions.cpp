class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        while( i < s.size()){
            if(s[i] == 'c'){
                if( i >=2 && s[i-1] == 'b' && s[i-2] == 'a'){
                    s = s.substr(0,i-2) + s.substr(i+1);
                }
                else{
                    return false;
                }
                i -=3;
            }
            i++;
        }
        return i==0;
    }
};
