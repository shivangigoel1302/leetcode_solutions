class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long int j = 0;
        long long int ans = 0;
        long long int i = 0;
        long long int s = nums.size();
        long long int count = 0;
        while(ans < n){
            if(i < s  && ans + 1 >= nums[i]){
                ans += nums[i];
                i++;
            }

            else{
                count += 1;
                ans += ans + 1;
            }

        }
        return count;
    }
};
