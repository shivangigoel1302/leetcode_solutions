class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0,possible = 0,limit=0;

        if(nums.size() < 1){
            return nums.size();
        }
        if(nums[0] == 0) return 0;
        for(int i = 0 ; i < nums.size(); i++){
            if( i == nums.size()-1){
                return step;
            }
            if(i == limit){
                step += 1;
                possible = max(possible,nums[i]+i);
                limit = possible;
               continue;
            }
            possible = max(possible,nums[i]+i);
        }
        return step;
    }
};
