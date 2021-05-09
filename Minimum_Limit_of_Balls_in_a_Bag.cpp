class Solution {
public:
    int getsize(int mid, vector<int>&nums){
        int s = 0;
        for(auto val : nums){
            if(val > mid){
                s += (val/mid + (val % mid != 0));
            }
            else{
                s+=1;
            }
        }
        return s;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int high = 0;
        for(auto it: nums){
            high = max(high,it);
        }
        int low = 1;
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            int sz = getsize(mid,nums);
            if(sz <= maxOperations + nums.size()){
                ans = min(ans,mid);
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
