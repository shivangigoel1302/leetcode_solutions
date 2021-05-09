class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size() +1;
        int preSum[n];
        preSum[0]=0;
        for(int i = 0; i < A.size(); i++){
            preSum[i+1] = A[i] + preSum[i];

        }
        int* count = new int[K];
        for(int i = 0 ; i < K; i++){
            count[i]= 0;
        }
        for(int i = 0 ; i < n; i++){

            count[(preSum[i]%K + K)% K]++;
        }
        int ans = 0;
        for(int i = 0 ; i < K; i++){
            ans += count[i]*(count[i] -1)/2;
        }

        return ans;
    }
};
