class Solution {
public:
    bool check(int mid, vector<int>weights,int D){
        int day = 1;
        int total = 0;
        int n = weights.size();
        bool valid = 1;
        for(int i = 0 ; i < n ; i++){
            if(weights[i] > mid){
                valid = 0;
            }
            if(weights[i] + total <= mid){
                total += weights[i];
            }
            else{
                day++;
                total = weights[i];
            }
        }
        if(!valid){
            return false;
        }
        return day <= D;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int high = 5*10000*50;
        int low = 1;
        while(low < high){
            int mid = (high + low)/2;
            if(check(mid,weights,D)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return high;
    }
};
