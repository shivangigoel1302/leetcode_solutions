class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,0);
        dp[0]=arr[0];
        int maximum = arr[0];
        for(int i = 1; i < k ; i++){
            maximum = max(maximum,arr[i]);
            dp[i]= maximum*(i+1);
        }
        for(int i = k ; i < n ; i++){
            maximum = arr[i];
            for(int j =1; j <=k ; j++){
                maximum = max(maximum, arr[i-j+1]);
                dp[i] = max(dp[i],dp[i-j] + maximum*(j));
            }
        }
        return dp[n-1];

    }
};
