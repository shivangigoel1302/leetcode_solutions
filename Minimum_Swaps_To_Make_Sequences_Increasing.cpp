class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int swap = 1;
        int noswap = 0;
        for(int i = 1; i < A.size(); i++){
            int iswap = INT_MAX;;
            int inoswap = INT_MAX;
            if(A[i-1] < A[i] && B[i-1] < B[i]){
                iswap = swap + 1;
                inoswap = noswap;
            }
            if(A[i-1] < B[i] && B[i-1] < A[i]){
                iswap = min(iswap,noswap +1);
                inoswap = min(inoswap,swap);
            }
            swap = iswap;
            noswap = inoswap;
        }
        return min(swap,noswap);
    }
};
