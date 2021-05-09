class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<vector<int>>len(n,vector<int>(n+1,0));
        len[0][1] = 1;

        for(int i = 1; i < n ;i++){
            for(int j = 0; j < i ; j++){
                if(nums[j] < nums[i]){
                    if(dp[i] <= dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        len[i][dp[i]] += len[j][dp[i]-1];
                    }
                }
            }
            len[i][1] = 1;
        }
       int maxlen = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = n; j>=0 ;j--){
                if(len[i][j] != 0){
                    maxlen = max(maxlen,j);
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += len[i][maxlen];
        }
        return ans;
    }
};
