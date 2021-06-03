class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>minEle(nums.size());
        minEle[0] = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
           // minEle[i] = min(minEle[i-1], nums[i-1]);
            if(nums[i] > min(minEle[i-1], nums[i-1]) ){
                minEle[i] = min(minEle[i-1], nums[i-1]);
            }
            else{
                minEle[i] = INT_MAX;
            }
        }
        stack<int>s;
        for(int i = nums.size() -1; i> 0 ;i--){
            while(!s.empty() && s.top() <= nums[i]){
                s.pop();
            }
            if(!s.empty()){
                if(s.top() > minEle[i]){
                    return true;
                }
            }
            s.push(nums[i]);
        }
        return false;
    }
};
