class Solution {
public:
    int helper(string s, char c){
        int cnt = 0;
        for(int i = 0; i < s.size(); i+=2){
            if(s[i] != c){
                cnt++;
            }
        }
        return cnt;
    }
    int minSwaps(string s) {
        int zero=0,one=0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                zero++;
            }
            else{
                one++;
            }
        }
        int n = s.size();
        if(n%2 == 0 && zero != one){
            return -1;
        }
        else if(n%2 && abs(zero-one) != 1){
            return -1;
        }
        if(zero > one){
            return helper(s,'0');
        }
        else if(one > zero){
            return helper(s,'1');
        }
        int opt1 = helper(s,'0');
        int opt2 = helper(s,'1');

        return min(opt1,opt2);
    }
};
