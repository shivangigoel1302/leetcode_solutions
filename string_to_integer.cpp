class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign =1;
        int num = 0;
        while(i < s.size() && s[i] ==' '){
            i++;
        }
        if(i<s.size() && (s[i] == '+' || s[i] =='-')){
            sign = (s[i] =='+') ? 1:-1;
            i++;
        }
        while(i < s.size() && s[i] >= '0' && s[i] <= '9'){
            if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i]-'0' > INT_MAX%10)){
                return (sign == 1) ?INT_MAX :INT_MIN;
            }
            num = num*10 + (s[i]-'0');
            i++;
        }
        return num*sign;
    }
};
