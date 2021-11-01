class Solution {
public:
    void finddiff(vector<int>&nums,int i,int n,vector<vector<int>>&dp,int num,int sum){
        if(i >= n){
            dp[num].push_back(sum);
            return;
        }

        finddiff(nums,i+1,n,dp,num+1,sum + nums[i]);

        finddiff(nums,i+1,n,dp,num,sum);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        int ans = INT_MAX;
        vector<vector<int>>dp((n/2)+1);
        dp[0].push_back(0);
        finddiff(nums,0,n/2,dp,0,0);

        vector<vector<int>>dp2((n/2)+1);
        finddiff(nums,n/2,n,dp2,0,0);
        dp2[0].push_back(0);
        for(int i = 0; i < n/2 + 1; i++){
            sort(dp2[i].begin(),dp2[i].end());
        }
        for(int i = 0; i <= n/2; i++){
           for(int j = 0; j < dp[i].size(); j++){
                   int a = dp[i][j];
                auto iter = lower_bound(dp2[n/2 - i].begin(), dp2[n/2 - i].end(), sum / 2 - a);
                if(iter != dp2[n/2 - i].end()){
                    ans = min(ans, abs(sum - 2 * (a + (*iter))));
                }

                if(iter != dp2[n/2 - i].begin()){
                    ans = min(ans, abs(sum - 2 * (a + (*prev(iter)))));
                }
           }
        }
        return ans;
    }
};
