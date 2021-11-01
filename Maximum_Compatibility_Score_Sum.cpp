class Solution {
public:
    int getscore(vector<int>&s,vector<int>&t){
        int score = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[i]){
                score++;
            }
        }
        return score;
    }
    int score(vector<vector<int>>&students,vector<vector<int>>&mentors,int tmask,int curr,vector<vector<int>>&dp){
        if(tmask == 0){
            return 0;
        }
        if(dp[curr][tmask] != -1){
            return dp[curr][tmask];
        }
        int ans = INT_MIN;
        for(int i = 0; i < students.size(); i++){
            if(tmask & (1 << i)){
                int compat = getscore(students[curr],mentors[i]);
                ans = max(ans, compat + score(students,mentors,tmask ^ (1 << i), curr+1,dp));
            }
        }
        return dp[curr][tmask] = ans;
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        vector<vector<int>>dp(n,vector<int>(1<<n,-1));
        return score(students,mentors,(1<<n)-1,0,dp);
    }
};
