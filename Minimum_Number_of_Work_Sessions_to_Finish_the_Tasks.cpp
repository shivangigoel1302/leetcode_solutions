class Solution {
public:
    int n;
    int dp[16][1<<14];
    int solve(vector<int>& tasks, int mask, int time, const int& sessionTime)
    {
        if(mask == 0) return 0;         // mask is zero means all tasks are finished

        if(dp[time][mask] != -1) return dp[time][mask];

        int ans = INT_MAX;

        for(int i=0; i<n; i++)
        {
            if((mask&(1<<i)))           // If ith task is available or not
            {
                if(time + tasks[i] <= sessionTime)        // If this task can be performed
                    ans = min(ans, solve(tasks, (mask^(1<<i)), time+tasks[i], sessionTime));    // Mark this as completed in ongoing session
                else
                    ans = min(ans, 1 + solve(tasks, (mask^(1<<i)), tasks[i], sessionTime)); // Mark this as completed and create a new session
            }
        }
        return dp[time][mask] = ans;
    }

    int minSessions(vector<int>& tasks, int sessionTime) {
        n = tasks.size();
        memset(dp, -1, sizeof(dp));
        return solve(tasks, (1<<n)-1, 0, sessionTime) + 1;
    }
};
