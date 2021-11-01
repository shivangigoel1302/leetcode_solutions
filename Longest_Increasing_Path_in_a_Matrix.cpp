class Solution {
public:
    int dp[201][201];
    int helper(vector<vector<int>>&matrix,int i,int j,int last){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()){
            return 0;
        }
        if(matrix[i][j] <= last){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int temp = 0;
        temp = max(helper(matrix,i+1,j,matrix[i][j]),helper(matrix,i-1,j,matrix[i][j]));
        temp = max(temp,max(helper(matrix,i,j-1,matrix[i][j]),helper(matrix,i,j+1,matrix[i][j])));
        return dp[i][j] = temp +1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int ans = 1;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans,helper(matrix,i,j,INT_MIN));
            }
        }
        return ans;
    }
};
