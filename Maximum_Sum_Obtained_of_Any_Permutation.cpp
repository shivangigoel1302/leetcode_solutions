class Solution {
public:

    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        priority_queue<int>pq;
        int mod = 1e9 + 7;
        long long int ans = 0;
        vector<int>dp(nums.size() + 1,0);
        for(int i = 0 ; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        for(int i = 0 ; i < requests.size(); i++){
           dp[requests[i][0]] += 1;
            dp[requests[i][1] + 1]-=1;
        }
        for(int i = 1 ; i < dp.size(); i++){
            dp[i] += dp[i-1];
            dp[i]%= mod;
        }
        sort(dp.begin(),dp.end());
        for(int i = dp.size()-1 ; i >=0 && dp[i] != 0; i--){
            long long int a = pq.top();
            a%=mod;
            pq.pop();
            long long temp = (a*dp[i])%mod;
            ans += temp;
            ans %= mod;
        }
        return ans%mod;
    }
};
