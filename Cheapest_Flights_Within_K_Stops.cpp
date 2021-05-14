class Solution {
public:
       int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int d, int K) {
        const int INF = 1e9;
        vector<vector<int>> dp(K + 2, vector<int>(n, INF));
        dp[0][s] = 0;
         for (int i = 1; i <= K + 1; ++i) {
            dp[i][s] = 0;
            for (const auto& x : flights)
                  dp[i][x[1]] = min(dp[i][x[1]], dp[i-1][x[0]] + x[2]);
            }
            return dp[K + 1][d] >= INF ? -1 : dp[K + 1][d];

        }
};
