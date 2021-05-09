class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int>dp(books.size(),0);
        int n = books.size();
        dp[n-1] = books[n-1][1];
        for(int i = n-2; i>=0; i--){
            dp[i] = dp[i+1] + books[i][1];
        }
        for(int i = n-2; i >=0 ; i--){
            int curr=0;
            int j = i;
            int maxh = 0;
            while(j < n && curr + books[j][0] <= shelf_width){
                maxh = max(maxh,books[j][1]);
                curr += books[j][0];
                if(j == n-1){
                    dp[i] = min(dp[i],maxh);
                }
                else{
                    dp[i] = min(dp[i],maxh + dp[j+1]);
                }
                j++;
            }
        }
        return dp[0];
    }
};
