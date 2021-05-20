class Solution {
public:
    int dp[101][202];
    int stonegame(vector<int>&piles,int i,int m){
        if(i >= piles.size()){
            return 0;
        }
        if(dp[i][m] != -1){
            return dp[i][m];
        }
        int total = 0;
        int ans = INT_MIN;
        for(int j = 0; j < 2*m && i + j < piles.size(); j++){
            total += piles[i+j];
            ans = max(ans,total - stonegame(piles,i+j+1,max(j+1,m)));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int sum = 0;
        for(auto it: piles){
            sum += it;
        }
        memset(dp,-1,sizeof(dp));
        int alice = stonegame(piles,0,1);
        return (sum + alice)/2;
    }
};
