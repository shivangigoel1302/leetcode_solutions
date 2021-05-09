class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int minr = 0;
        for(auto x :houses){
            int l = 0;
            int r = heaters.size()-1;
            while(l < r){
                int mid = l+r >> 1;
                if(heaters[mid] >= x){
                    r = mid;
                }
                else{
                    l = mid+1;
                }
            }
            int dist = r > 0 ? min(abs(x-heaters[r-1]),abs(x-heaters[r])) : abs(x- heaters[r]);
            minr = max(minr,dist);
        }
        return minr;
    }
};
