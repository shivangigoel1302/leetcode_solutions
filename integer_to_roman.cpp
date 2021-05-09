class Solution {
public:
    string intToRoman(int num) {
        string roman[] = {"M", "CM","D","CD","C","XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int integer[] =  {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ans ="";
        for(int i = 0 ; num > 0; i++){
            while(num>=integer[i]){
                ans = ans + roman[i];
                num = num - integer[i];
            }
        }
        return ans;
    }
};
