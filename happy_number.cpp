class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
        {
            return true;
        }
        if(n==4)
        {
            return false;
        }
        int sum=0;
        while(n>0)
        {
            int digit=n%10;
            sum+=digit*digit;
            n=n/10;
        }
        return isHappy(sum);
    }
};
