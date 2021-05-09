 bool compare(vector<int>a,vector<int>b){
        if(a[1] != b[1]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        vector<int>dp(pairs.size(),1);
        int ans = 1;
        for(int i = 0; i < pairs.size(); i++){
            for(int j = 0; j < i ; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};
