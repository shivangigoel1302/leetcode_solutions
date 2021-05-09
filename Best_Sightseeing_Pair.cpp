class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int ans = 0;
        int maxi = A[0];
        int index = 0;
        for(int i = 1 ; i < n; i++){
            ans = max(ans, A[i] + maxi + index-i);
            if(A[i] >= maxi + index-i){
                maxi = A[i];
                index = i;
            }
        }
        return ans;
    }
};
