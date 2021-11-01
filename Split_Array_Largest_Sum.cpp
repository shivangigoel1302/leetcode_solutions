class Solution {
public:
    int findpartition(vector<int>&nums,int mid){
        int start = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > mid){
                sum = nums[i];
                start++;
            }
        }
        return start;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = INT_MIN;
        int r = 0;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            l = max(l,nums[i]);
            r += nums[i];
        }
        while(l <= r){
            int mid = (l+r)/2;
            int x = findpartition(nums,mid);
            if(x <= m){
                ans = mid;
                r = mid-1;
            }

            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
