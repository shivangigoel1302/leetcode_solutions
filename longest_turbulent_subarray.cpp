class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int best = 0;
        int longest = 0;
        for(int i = 0 ; i < A.size(); i++){
            if(i >= 2 && ((A[i-2] > A[i-1] && A[i-1] < A[i]) || (A[i-2] < A[i-1] && A[i-1] > A[i]))){
                longest++;
            }
            else if( i>=1 && A[i] != A[i-1]){
                longest = 2;
            }
            else {
                longest = 1;
            }
            best = max(best,longest);
        }
        return best;
    }
};
