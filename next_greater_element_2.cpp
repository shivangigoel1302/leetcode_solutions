class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>left;
        stack<int>right;
        vector<int>v(nums.size());
        int n = nums.size();
        for(int i = n-2 ; i >=0 ;i--){
            left.push(i);
        }
        for(int i = n-1; i>=0; i--){
            while(!right.empty() && nums[i] >= nums[right.top()]){
                right.pop();
            }
            if(right.empty()){
                    while(!left.empty() && nums[i] >= nums[left.top()]){
                    left.pop();
                }
            }
            if(right.empty() && left.empty()){
                v[i] = -1;
            }
            else if(right.empty()){
                v[i] = nums[left.top()];
            }
            else{
                v[i] = nums[right.top()];
            }
            right.push(i);
        }
        return v;
    }
};
