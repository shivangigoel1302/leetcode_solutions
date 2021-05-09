class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
        }
        sum-=x;
        if(sum < 0 ) return -1;
        if(sum == 0) return nums.size();
        int start = 0;
        int len = INT_MIN;
        int val = 0;
        for(int i =0 ; i < nums.size(); i++){
            if(val < sum){
                val += nums[i];
            }
            while(val >= sum){
                if(val == sum){
                    len = max(len,i-start+1);
                }
                val -= nums[start++];
            }
        }
        if(len == INT_MIN) return -1;
        return nums.size()-len;
    }
};
