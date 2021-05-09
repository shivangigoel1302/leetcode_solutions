class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v = nums;
        if(nums.size() == 1){
            return 0;
        }
        sort(v.begin(),v.end());
        int l = 0 ;
        int r = nums.size() -1 ;
        for(int i = 0 ; i < nums.size(); i++){
            if(v[i] != nums[i]){
                r = min(r,i);
                l = max(l,i);
            }
        }
        if(l-r>=0){
            return l-r+1;
        }
        return 0;
    }
};
