class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int arrsum=0,curval=0;
        for(int i=0;i<A.size();i++)
        {
            arrsum = (long)arrsum + A[i];
            curval = (long)curval + i*(long)A[i];
        }
        int maxval=curval,t;
        for(int i=1;i<A.size();i++)
        {
            t=(long)curval+arrsum-(A.size())*(long)A[A.size()-i];
            maxval=max(maxval,t);
            curval=t;
        }
        return maxval;
    }
};
