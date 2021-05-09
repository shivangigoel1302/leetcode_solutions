class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int k = piles.size()-2;
        int i = 0;
        int ans = 0;
        while(i<k){
            ans+=piles[k];
            i++;
            k-=2;
        }
        return ans;
    }
};
