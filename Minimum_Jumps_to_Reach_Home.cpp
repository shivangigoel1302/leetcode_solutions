class Solution {
public:
    unordered_set<int>s;
    int dp[6005][2];
    int destination(int a , int b , int target, int curr, int count){
        if(target == curr){
            return 0;
        }
        if(s.find(curr) != s.end() || curr < 0 || curr > 6000){
            return 1e9;
        }
        if(dp[curr][count] != -1){
            return dp[curr][count];
        }
        dp[curr][count] = 1+ destination(a,b,target,curr + a,0 );
        if(count == 0){
            dp[curr][count] = min(dp[curr][count], 1 + destination(a,b,target,curr - b,1));
        }
        return dp[curr][count];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(auto i : forbidden){
            s.insert(i);
        }
        memset(dp,-1,sizeof(dp));
        int ans = destination(a,b,x,0,0);
        return ans >= 1e9? -1 : ans;
    }
};
