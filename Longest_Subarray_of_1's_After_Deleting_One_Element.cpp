class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int i = 0;
        int maxlen = INT_MIN;
        int n = nums.size();
        while(i < nums.size()){
            if(nums[i] == 0){
                int l = i;
                int r = i;
                while(l >0 && nums[l-1] == 1){
                    l--;
                }
                while(r < n-1 && nums[r+1] == 1){
                    r++;
                }

                maxlen = max(maxlen, r-l);
            }
            i++;
        }
        if(maxlen == INT_MIN){
            return nums.size() -1;
        }
        return maxlen;
    }
};
