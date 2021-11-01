class Solution {
public:
    int maximum69Number (int num) {
        int curr = 10;
        while(num/curr > 0){
            curr = curr*10;
        }
        curr/=10;
        while(curr){
            if((num/curr)%10 == 6){
                int temp = num/curr+3;
                num = num%curr + temp*curr;
                return num;
            }
            curr/=10;
        }
        return num;
    }
};
