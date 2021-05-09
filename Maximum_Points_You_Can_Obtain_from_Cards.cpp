class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int>lsum(cardPoints.size()+1,0);
        vector<int>rsum(cardPoints.size() + 1, 0);
        int n = cardPoints.size();
        lsum[1] = cardPoints[0];
        for(int i = 1; i < cardPoints.size(); i++){
            lsum[i+1] = lsum[i]+ cardPoints[i];
        }
        rsum[n-1] = cardPoints[n-1];
        for(int i = n-2; i >=0 ; i--){
            rsum[i] = rsum[i+1] + cardPoints[i];
        }
        int ans = 0;
        for(int i = 0 ; i <=k  ; i++){
            int j = n- k + i;
            ans = max(ans, lsum[i] + rsum[j]);
        }
        return ans;
    }
};
