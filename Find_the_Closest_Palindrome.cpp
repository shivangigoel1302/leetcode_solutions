class Solution {
public:
    string nearestPalindromic(string n) {
        int digits = n.length();
        if(digits == 1)
        {
            return to_string(n[0] - '0' - 1);
        }
        long num = stol(n);
        long ans = 0, half = 0, rem = 0, div = 0, rev_half = 0, high = 0, low = 0, mid = 0;
        if(isPowerOf10(num))
        {
            return to_string(num-1);
        }
        if(isPowerOf10(num-1))
        {
            return to_string(num-2);
        }
        if(isPowerOf10(num+1))
        {
            return to_string(num+2);
        }
        if(digits % 2 == 0)
        {
            // even
            div = (int)pow(10,digits/2);
            half = num/div;
            rem = num % div;
            rev_half = rev(half);
            if(rev_half > rem)
            {
                high = half*div + rev_half;
                low = (half-1)*div + rev(half-1);
            }
            else if(rev_half < rem)
            {
                low = half*div + rev_half;
                high = (half+1)*div + rev(half+1);
            }
            else
            {
                low = (half-1)*div + rev(half-1);
                high = (half+1)*div + rev(half+1);
            }
        }
        else
        {
            div = (int)pow(10,digits/2);
            half = num/div;
            mid = (half)%10;
            rem = num % div;
            rev_half = rev(half/10);
            if(rev_half > rem)
            {
                high = half*div + rev_half;
                low = (half-1)*div + rev((half-1)/10);
            }
            else if(rev_half < rem)
            {
                low = half*div + rev_half;
                high = (half+1)*div + rev((half+1)/10);
            }
            else
            {
                low = (half-1)*div + rev((half-1)/10);
                high = (half+1)*div + rev((half+1)/10);
            }
        }
        ans = low;
        if(num - low > high - num)
        {
            ans = high;
        }
        return to_string(ans);
    }
    long rev(long n)
    {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(s);
    }
    bool isPowerOf10(long n)
    {
        int digits = ceil(log10(n));
        return n%((long)pow(10,digits)) == 0;
    }
};
