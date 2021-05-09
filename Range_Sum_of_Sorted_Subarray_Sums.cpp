class Solution {
public:
    int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>v;
        for(int i = 0 ; i < nums.size(); i++){
            v.push_back(nums[i]);
            int sum = nums[i];
            for(int j = i+1 ; j < nums.size(); j++){
                sum += nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        int sum = 0;
        for(int i = left - 1; i <= right-1; i++){
            sum += v[i];
            sum %= mod;
        }
        return sum %mod;
    }
};
