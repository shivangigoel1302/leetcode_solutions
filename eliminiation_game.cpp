class Solution {
public:

    int lastRemaining(int n) {
        int s=1;
        int e=n;
        int i=1;
        while(s!=e)
        {
            if(n%2!=0)
            {
                s+=pow(2,i-1);
                e-=pow(2,i-1);
            }
            else
            {
                if(i%2!=0)
                {
                    s+=pow(2,i-1);
                }
                else
                {
                    e-=pow(2,i-1);
                }
            }
            i++;
            n=n/2;
        }
        return s;
    }
};
