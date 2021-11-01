class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        stack<int>s;
        vector<int>left(nums.size(),-1);
        s.push(0);
        int ans = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            while(!s.empty() && nums[s.top()] >= nums[i]){
                s.pop();
            }
            if(s.empty()){
                left[i] = -1;
            }
            else{
                left[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        vector<int>right(nums.size());
        for(int i = nums.size()-1; i >=0; i--){
            while(!s.empty() && nums[s.top()] >= nums[i]){
                s.pop();
            }
            if(s.empty()){
                right[i] = nums.size();
            }
            else{
                right[i] = s.top();
            }
            s.push(i);
        }
        for(int i = 0; i < nums.size(); i++){
            int l = left[i] +1;
            int r = right[i] - 1;
            if(l <= k && r >= k){

                ans = max(ans, (r-l+1)*nums[i]);
            }
        }
        return ans;



//          int lowest = nums[k], ans = nums[k];
//         int l = k, r = k;
//         int n = nums.size();
//         while(l >= 0 || r <= n - 1) {
//             while(l > 0) {
//                 if(nums[l - 1] < lowest) break;
//                 --l;
//             }
//             while(r < n - 1) {
//                 if(nums[r + 1] < lowest) break;
//                 ++r;
//             }
//             ans = max(ans, (r - l + 1) * lowest);
//             if(l == 0 && r != n - 1) {
//                 lowest = nums[r + 1];
//             } else if(l == 0 && r == n - 1) {
//                 break;
//             } else if(l != 0 && r == n - 1) {
//                 lowest = nums[l - 1];
//             } else {
//                 lowest = max(nums[l - 1], nums[r + 1]);
//             }
//         }
//         return ans;
    }
};
