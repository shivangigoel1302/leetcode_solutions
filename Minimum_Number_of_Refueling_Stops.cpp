class Solution {
public:

    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int ans = 0;
        sort(stations.begin(),stations.end(),[](vector<int>v1,vector<int>v2){
            return v1[0] < v2[0];
        });

        int fuel = startFuel;
        int prev = 0;
        for(int i = 0; i < stations.size(); i++){
            fuel -= stations[i][0] - prev;
            while(fuel < 0 && !pq.empty()){
                int val = pq.top();
                pq.pop();
                ans++;
                fuel += val;
            }
            if(fuel < 0){
                return -1;
            }
            pq.push(stations[i][1]);
            prev = stations[i][0];
        }
        fuel -= target - prev;
        while(!pq.empty() && fuel < 0){
            ans++;
            fuel += pq.top();
            pq.pop();
        }
        if(fuel < 0){
            return -1;
        }
        return ans;


//         int N = stations.length;
//         long[] dp = new long[N + 1];
//         dp[0] = startFuel;
//         for (int i = 0; i < N; ++i)
//             for (int t = i; t >= 0; --t)
//                 if (dp[t] >= stations[i][0])
//                     dp[t+1] = Math.max(dp[t+1], dp[t] + (long) stations[i][1]);

//         for (int i = 0; i <= N; ++i)
//             if (dp[i] >= target) return i;
//         return -1;
    }
};
