class Solution {
public:
    int arrangeCoins(int n) {
       long long int l=0;
        long long int r=n;
        while(l<=r)
        {
            long long int mid=(l+r)/2;
           long long int curr=mid*(mid+1)/2;
            if(curr==n)
            {
                return mid;
            }
            if(curr<n)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return r;
    }
};
