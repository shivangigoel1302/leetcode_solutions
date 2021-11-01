class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long int odd = nums[0];
        long long int even = 0;
        for(int i = 1; i < nums.size(); i++){
            long long int neven = even;
            long long int nodd = odd;
            if(even < odd - nums[i]){
                neven = odd - nums[i];
            }
            if(odd < even + nums[i]){
                nodd = even + nums[i];
            }
            odd = nodd;
            even = neven;
        }
        return max(odd,even);
    }
};
