class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&job,int d,int i){
        if(i >= job.size()){
            if(d == 0){
                return 0;
            }
            return INT_MAX;
        }
        if(d <= 0){
            return INT_MAX;
        }
        if(dp[i][d] != -2){

            return dp[i][d];
        }
        int ans = INT_MAX;
        int currmax = job[i];
        for(int j = i; j < job.size(); j++){
            currmax = max(currmax,job[j]);
            int temp = helper(job,d-1,j+1);

            if(temp == INT_MAX){
                continue;
            }
            ans = min(ans,currmax + temp);
        }
        return dp[i][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        dp.resize(301,vector<int>(11,-2));
        int ans = helper(jobDifficulty,d,0);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
