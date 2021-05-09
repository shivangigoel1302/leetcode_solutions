class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        map<int,int>m;
        m[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i < A.size(); i++){
            sum += A[i];
            if(m.find(sum - S) != m.end()){
                count+= m[abs(sum-S)];
            }
            m[sum]++;
        }
        return count;
    }
};
