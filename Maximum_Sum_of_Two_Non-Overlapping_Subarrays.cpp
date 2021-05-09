class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        if(M + L == A.size()){
            int sum = 0;
            for(int i = 0 ; i < A.size(); i++){
                sum += A[i];
            }
            return sum;
        }
        map<int,int>ml,mm;
        int sum = 0;
        for(int i = 0 ; i <= A.size(); i++){
            if(i < L){
                sum += A[i];
            }
            else{
                ml[i-L] = sum;
                sum = sum - A[i-L] + A[i];
            }
        }
         sum = 0;
        for(int i = 0 ; i <= A.size(); i++){
            if(i < M){
                sum += A[i];
            }
            else{
                mm[i-M] = sum;
                sum = sum - A[i-M] + A[i];
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i <= (int)A.size() - L; i++){
            for(int j = i + L; j <= (int)A.size() - M; j++){
                ans = max(ans,ml[i] + mm[j]);
            }
        }
        for(int i = 0 ; i <= (int)A.size() - M; i++){
            for(int j = i + M; j <= (int)A.size() - L; j++){
                ans = max(ans,mm[i] + ml[j]);
            }
        }
        return ans;
    }
};
