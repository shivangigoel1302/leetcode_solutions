class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        unordered_set<int>s;
        vector<vector<int>>dp(N,vector<int>(N));
        for(auto m : mines){
            s.insert(m[0]*N + m[1]);
        }
        int ans = 0,count = 0;
        for(int r = 0 ; r < N; r++){
            count = 0;
            for(int c = 0 ; c < N ; c++){
                count = s.find(r*N + c) != s.end() ? 0 : count + 1;
                dp[r][c] = count;
            }
            count = 0;
            for(int c = N-1 ; c >=0 ; c--){
                count = s.find(r*N + c) != s.end() ? 0 : count + 1;
                dp[r][c] = min(dp[r][c],count);
            }
        }
        count = 0;
        for(int c = 0 ; c < N ; c++){
            count = 0;
            for(int r = 0 ; r < N; r++){
                count = s.find(r*N + c) != s.end() ? 0 : count + 1;
                dp[r][c] = min(dp[r][c],count);
            }
            count = 0;
            for(int r = N-1 ; r >=0 ; r--){
                count = s.find(r*N + c) != s.end() ? 0 : count + 1;
                dp[r][c] = min(dp[r][c],count);
                ans = max(ans,dp[r][c]);
            }
        }
        return ans;
    }
};
