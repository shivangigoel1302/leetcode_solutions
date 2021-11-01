class Solution {
public:
    int minPairSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()/2; i++){
            ans = max(ans,(long long)nums[i] + nums[n-1-i]);
        }
        return ans;
    }
};
