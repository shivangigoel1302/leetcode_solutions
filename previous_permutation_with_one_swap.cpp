class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        for(int i = A.size()-1; i>0; i--){
            if(A[i] < A[i-1]){
                int minindex = i-1;
                int diff = INT_MAX;
                for(int j = i; j< A.size(); j ++){
                    if(A[j] - A[i-1] < diff){
                        minindex = j;
                        diff = A[j] - A[i];
                    }
                }
                swap(A[minindex], A[i-1]);
                return A;
            }
        }
        return A;
    }
};
