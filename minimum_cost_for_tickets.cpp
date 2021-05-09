class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         int dp[366] = {0};

    // Base case
    dp[days[0]] = min(costs[0], min(costs[1], costs[2]));

    int lastCostIndex = 0;

    for(int i = 1; i < days.size(); i++)
    {
        // Case 0:
        int cache = dp[days[i-1]] + costs[0];

        // Case 1:
        int j = days[i]-7 > 0 ? days[i]-7 : 0;
        while(j >= 1 && dp[j] == 0) j--;
        cache = min(cache, dp[j] + costs[1]);

        // Case 2:
        int k = days[i]-30 > 0 ? days[i]-30 : 0;
        while(k >= 1 && dp[k] == 0) k--;
        cache = min(cache, dp[k] + costs[2]);

        dp[days[i]] = cache;
    }

    return dp[days.back()];
    }
};
