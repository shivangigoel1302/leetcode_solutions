class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for(int i = 0 ; i < nums.size(); i++){
            bitmask ^= nums[i];
        }
        int diff = bitmask & (-bitmask);
        vector<int>ans(2);
        for(int i = 0 ; i < nums.size();  i++){
            if((nums[i]& diff )==0){
                ans[0] ^= nums[i];
            }
            else{
                ans[1]^= nums[i];
            }
        }
        return ans;
    }
};
