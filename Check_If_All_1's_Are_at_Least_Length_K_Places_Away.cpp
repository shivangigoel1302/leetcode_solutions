class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        stack<int>s;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 1){
                if(!s.empty()){
                    if(i - s.top() <= k) return false;
                }
                s.push(i);
            }
        }
        return true;
    }
};
