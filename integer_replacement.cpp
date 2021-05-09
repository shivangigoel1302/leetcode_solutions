class Solution {
public:
    int integerReplacement(int n) {
        if(n==1||n==0)
        {
            return 0;
        }
        if(n==INT_MAX)
        {
            return 32;
        }
        if(n%2==0)
        {
            return 1+integerReplacement(n/2);
        }
        else
        {
            return 1+min(integerReplacement((n+1)/2)+1,integerReplacement(n-1));
        }
    }
};
