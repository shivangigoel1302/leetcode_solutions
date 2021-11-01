class Solution {
public:
    long long convert(int n,int d,int ld){
        long long curr = 1;
        long long a=0;
        while(n > 0){
            int dig = n%10;
            if(dig == ld){
                a += d*curr;
            }
            else{
                a += dig*curr;
            }
            curr*=10;
            n = n/10;
        }
        return a;
    }
    int maxDiff(int num) {
        long long int n = num;
        long long pow = 10;
        while(n/pow > 0){
            pow *= 10;
        }
        int ld=9;
        while(num > 0){
            int dig = num%10;
            if(dig != 9){
              ld = dig;
            }
            num/=10;
        }
        long long a = 0;
        a = convert(n,9,ld);
        pow/=10;
        long long b = n;
            if(n/pow == 1){
                pow /= 10;
                while(pow && (n/pow)%10 <= 1){
                    pow = pow/10;
                }
                if(pow){
                   ld = (n/pow)%10;
                   b = convert(n,0,ld);
                }
            }
            else
            {

                b = convert(n,1,n/pow);
            }
        return a-b;
    }
};
