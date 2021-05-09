class Solution {
public:
    bool ispossible(vector<int>piles,int H, int mid){
        int time = 0;
        for(int i = 0 ; i < piles.size(); i++){
            time += piles[i]/mid;
            time += piles[i]%mid?1:0;
        }
        return time <= H;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = INT_MIN;
        for(int i = 0 ; i <piles.size(); i++){
            r = max(r,piles[i]);
        }
        int ans = INT_MAX;
        while(l <= r){
            int mid=(l+r)/2;
            if(ispossible(piles,H,mid)){
                ans = min(ans,mid);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
