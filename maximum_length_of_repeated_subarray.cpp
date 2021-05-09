class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int dp[A.size() +1][B.size() +1];
        int ans = 0;

        for(int i =0 ; i< B.size()+1 ;i++){
            for(int j = 0; j< A.size()+1; j++){
                dp[i][j] = 0;
            }
        }
        for(int i = B.size()-1 ; i >=0; i--){
            for(int j = A.size()-1; j>=0; j--){
                //dp[i][j] = 0;
                if(A[i] == B[j]){
                    dp[i][j] = dp[i+1][j+1]+1;
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};
