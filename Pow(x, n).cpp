class Solution {
public:
    double myPow(double x, int n) {
        double ans =1 ;
        while(n){
            if(n%2){
                if(n > 0){
                    ans = ans * x;
                }
                else{
                    ans = ans/x;
                }
            }
            x = x*x;
            n = n/2;
        }
        return ans;
    }
};
