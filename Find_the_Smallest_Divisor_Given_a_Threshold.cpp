class Solution {
public:
    int findsum(vector<int>nums,int t, int mid){
        int sum = 0;
        for(auto it: nums){
            sum += it/mid;
            if(it%mid){
                sum++;
            }
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int r = *max_element(nums.begin(),nums.end());
        int l = 1;
        int diff = INT_MAX;
        int ans = threshold;
        while(l <= r){
            int mid = (l+r)/2;
            int x = findsum(nums,threshold,mid);
            if(x > threshold){
                l = mid+1;
            }
            else{
                if(threshold - x <= diff){
                    diff = threshold - x;
                    ans = mid;
                }
                r = mid-1;
            }

        }
        return ans;
    }
};
