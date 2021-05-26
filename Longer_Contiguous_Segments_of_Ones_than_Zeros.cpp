class Solution {
public:
    bool checkZeroOnes(string s) {
        int i = 0;
        int one =0,zero=0;
        while(i < s.size()){
            int j = i+1;
            while(j < s.size() && s[i] == s[j]){
                j++;
            }
            if(s[i] == '1'){
                one = max(one,j-i);
            }
            else{
                zero = max(zero,j-i);
            }
            i = j;
        }
        return one > zero;
    }
};
