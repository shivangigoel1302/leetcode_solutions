class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = 0;
        int sum = 0;
        int inf = 1e9;
        int ans = inf;
        vector<int>dp(arr.size(),inf);
        for(int r= 0 ;r < arr.size(); r++){
            sum += arr[r];
             while(sum > target){
                sum -= arr[l];
                l++;
            }
            if(sum == target){
                int len = r-l+1;
                dp[r] = len;
                if(l > 0){
                    ans = min(ans,len + dp[l-1]);
                }
            }

            if(r > 0){
                dp[r] = min(dp[r],dp[r-1]);
            }
        }
        if(ans == inf){
            return -1;
        }
        return ans;
    }
};
