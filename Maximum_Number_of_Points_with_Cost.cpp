class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points[0].size();
        int m = points.size();
        vector<long long int>dp(n,0);
        for(int i = 0; i < n; i++){
            dp[i] = points[0][i];
        }
        vector<long long int>last(n,0);
        vector<long long int>left(n,0);
        vector<long long int>right(n,0);
        for(long long int j = 1; j < m; j++){
            for(int i = 0; i < n; i++){
                last[i] = dp[i];
            }
            left[0] = last[0];
            right[n-1] = last[n-1];
            for(int i = 1; i < n; i++){
                left[i] = max(last[i],left[i-1]-1);
            }
            for(int i = n-2; i>=0; i--){
                right[i] = max(last[i],right[i+1]-1);
            }
            for(int i = 0; i < n; i++){
                dp[i] = max(left[i],right[i]) + points[j][i];
            }
        }
        long long int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points[0].size();
        int m = points.size();
        vector<long long int>dp(n,0);
        for(int i = 0; i < n; i++){
            dp[i] = points[0][i];
        }
        vector<long long int>last(n,0);
        vector<long long int>left(n,0);
        vector<long long int>right(n,0);
        for(long long int j = 1; j < m; j++){
            for(int i = 0; i < n; i++){
                last[i] = dp[i];
            }
            left[0] = last[0];
            right[n-1] = last[n-1];
            for(int i = 1; i < n; i++){
                left[i] = max(last[i],left[i-1]-1);
            }
            for(int i = n-2; i>=0; i--){
                right[i] = max(last[i],right[i+1]-1);
            }
            for(int i = 0; i < n; i++){
                dp[i] = max(left[i],right[i]) + points[j][i];
            }
        }
        long long int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
