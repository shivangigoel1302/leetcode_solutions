class Solution {
public:
    int sum=0;
    int slices(vector<int>A,int i)
    {
        if(i<2)
        {
            return 0;
        }
        int pv=0;
        if(A[i]-A[i-1]==A[i-1]-A[i-2])
        {
            pv=1+slices(A,i-1);
            sum+=pv;
        }
        else
        {
            slices(A,i-1);
        }
        return pv;
    }
    int numberOfArithmeticSlices(vector<int>& A) {

        int ans=slices(A,A.size()-1);
        return sum;
    }

};
