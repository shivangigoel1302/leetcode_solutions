class Solution {
public:
    int mySqrt(int x) {
        if(x==1)
        {
            return 1;
        }
        long long int l=0;
        long long int r=ceil(float(x/2));
        while(l<=r)
        {
           long long int mid=(l+r)/2;
            if(mid*mid==x)
            {
                return mid;

            }
            if(mid*mid<x)
            {
                l=mid+1;
            }
            else if(mid*mid>x)
            {
                r=mid-1;
            }
        }
        return r;
    }
};
