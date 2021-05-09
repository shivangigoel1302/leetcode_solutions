/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      long long int l=1;
       long long int r=n;
        while(l<=r)
        {
          long long int mid=(l+r)/2;
        int val=guess(mid);
        if(val==-1)
        {
            r=mid;
        }
        else if(val==1)
        {
            l=mid+1;
        }
        else
        {
            return mid;
        }
        }
        return 0;
    }
};
