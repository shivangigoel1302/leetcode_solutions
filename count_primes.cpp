class Solution {
public:
    bool isprime(int num){
        for(int a=2; a*a<=num;a++){
            if(num%a==0)
                return false;

        }
        return true;
    }
    int countPrimes(int n) {
        int count=1;
        if(n<=2)
        {
            return 0;
        }
        if(n<=3)
        {
            return 1;
        }
        for(int i=3;i<n;i+=2)
        {
           if(isprime(i))
         {
            count++;
         }
        }
        return count;
    }
};
