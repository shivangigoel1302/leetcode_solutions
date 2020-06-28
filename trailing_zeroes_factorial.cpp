class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        long long int d=5;
        while(n/d>=1)
        {
            int ans=n/d;
            sum+=ans;
            d=d*5;
        }
        return sum;
    }
};
