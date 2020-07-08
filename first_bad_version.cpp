// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==0)
        {
            return 0;
        }
       long long int l=1;
       long long int r=n;
        while(l<r)
        {
          long long  int mid=(l+r)/2;
            if(isBadVersion(mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
