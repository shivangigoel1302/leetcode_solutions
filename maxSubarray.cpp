class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int l = nums[0];
        int g= l;
        for(int i =1 ; i<nums.size();  i++){
            l = max(l+nums[i], nums[i]);
            g= max(g,l);
        }
        return g;
    }
};
