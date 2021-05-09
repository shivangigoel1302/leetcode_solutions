class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
        {
            return 1;
        }
        int ans=9;
        int factorial=9;
        for(int i=1;i<n;i++)
        {
            ans=ans*factorial;
            factorial--;
        }
        return ans+countNumbersWithUniqueDigits(n-1);
    }
};
