class Solution {
public:
    int getcost(vector<int>houses,int start,int end){
        int len = end-start+1;
        int median;
        if(len%2 == 0){
            int mid = (end-start)/2;
            median = (houses[start + mid] + houses[start + mid+1])/2;
        }
        else{
            int mid = (end-start)/2;
            median = houses[start + mid];
        }
        int cost = 0;
        for(int i = start ; i <= end; i++){
            cost += abs(median- houses[i]);
        }
        return cost;
    }
    int helper(vector<int>&houses,int k,int start,vector<vector<int>>&dp){
        if(k == 0 || start >= houses.size()){
            return 0;
        }
        if(dp[start][k] != -1){
            return dp[start][k];
        }
        int ans = INT_MAX;
        for(int e = start ; e < houses.size(); e++){
            if(k != 1 || e == houses.size()-1){
                int cost = getcost(houses,start,e);
                ans = min(ans,cost + helper(houses,k-1,e+1,dp));
            }
        }
        return dp[start][k] = ans;
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        if(k == houses.size()){
            return 0;
        }
        vector<vector<int>>dp(houses.size()+1,vector<int>(k+1,-1));
        return helper(houses,k,0,dp);
    }
};
