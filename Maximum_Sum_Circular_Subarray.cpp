class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = 0;
        for(int i = 0 ; i < A.size(); i++){
            sum += A[i];
        }
        int currmin = A[0],finalmin= A[0];
        int currmax = A[0],finalmax= A[0];
        for(int i = 1 ; i < A.size(); i++){
            currmin= min(currmin + A[i],A[i]);
            currmax = max(currmax + A[i],A[i]);
            finalmin= min(finalmin,currmin);
            finalmax = max(finalmax,currmax);
        }
        if(finalmax < 0){
            return finalmax;
        }
        return max(finalmax,sum - finalmin);
    }
};
