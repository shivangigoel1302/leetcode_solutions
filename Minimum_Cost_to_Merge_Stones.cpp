class Solution {
public:
    pair<int,int> helper(vector<int>&stones,vector<int>&sum,int k,vector<vector<pair<int,int>>>&dp,int i,int j){
        if(j-i+1 < k){
            return {0,j-i+1};
        }
        if(j-i+1 == k){
            int s = sum[j]- (i>0 ? sum[i-1] : 0);
            return {s,1};
        }
        if(dp[i][j].first != -1){
            return dp[i][j];
        }
        auto ans = make_pair(INT_MAX,-1);
        for(int q= i; q < j;q++){
            auto left = helper(stones,sum,k,dp,i,q);
            auto right = helper(stones,sum,k,dp,q+1,j);
            if(left.first != INT_MAX && right.first != INT_MAX && left.second + right.second <= k){
                int newc = left.first + right.first;
                int news = left.second + right.second;
                if(news == k){
                    newc += sum[j]- (i>0 ? sum[i-1] : 0);
                    news = 1;
                }
                if(ans.first > newc){
                    ans.first = newc;
                    ans.second = news;
                }
            }
        }
        dp[i][j] = ans;
        return ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        vector<int>sum(stones.size(),0);
        sum[0] = stones[0];
        for(int i = 1; i < stones.size(); i++){
            sum[i] = sum[i-1] + stones[i];
        }
        int n = stones.size();
        vector<vector<pair<int,int>>>dp(n, vector<pair<int, int>> (n, {-1, -1}));
        pair<int,int>p;
        p =helper(stones,sum,k,dp,0,stones.size()-1);
        return p.second == 1 ? p.first:-1;

    }
};
