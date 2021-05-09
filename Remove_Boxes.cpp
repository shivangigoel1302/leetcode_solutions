class Solution {
public:
    int dp[101][101][101];
   int helper(vector<pair<int,int>>box,int l, int r, int k){
       if(l >= r){
           return 0;
       }
       if(dp[l][r][k] != -1){
           return dp[l][r][k];
       }
       int ans = 0;
       ans = (k + box[l].second)*(k + box[l].second) + helper(box,l+1,r,0);
       for(int i = l +1 ; i < r; i++){
           if(box[i].first != box[l].first){
               continue;
           }
           ans = max(ans,helper(box,l+1,i,0) + helper(box,i,r,k + box[l].second));
       }
       dp[l][r][k] = ans;
       return ans;
   }
    int removeBoxes(vector<int>& boxes) {
        vector<pair<int,int>>box;
        int s= 0;
        memset(dp,-1,sizeof(dp));
        box.push_back({boxes[0],1});
        for(int i = 1; i < boxes.size(); i++){
            if(box[s].first != boxes[i]){
                box.push_back({boxes[i],1});
                s++;
            }
            else{
                box[s].second++;
            }
        }
        return helper(box,0,box.size(),0);
    }
};
