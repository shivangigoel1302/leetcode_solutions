class Solution {
public:
    bool isPowerOfFour(int num) {
        int twos = 0;
        if(num <=0 || num == 2)return false;
        if( num == 1) return true;
        while(num != 0 && (num & 1) == 0){
            twos++;
            cout<<num<<" ";
            num = num >> 1;
        }
        if(twos % 2 == 0 && twos != 0 && num == 1){
            return true;
        }
        return false;
    }
};
