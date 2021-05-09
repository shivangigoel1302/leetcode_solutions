class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int zero = 0;
        int start = 0;
        int ans = 0;
        for(int r = 0; r < A.size(); r++){
            if(A[r] == 0){
                zero++;
            }
            while(zero > k){
                if(A[start] == 0){
                    zero--;
                }
                start++;
            }
            ans = max(ans,r-start+1);
        }
        return ans;
    }
};
