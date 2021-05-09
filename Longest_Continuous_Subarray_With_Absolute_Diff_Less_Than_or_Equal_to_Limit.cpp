class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int>q1;
        deque<int>q2;
        q1.push_front(0);
        q2.push_front(0);
        int j = 0;
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            while(!q1.empty() && nums[q1.back()] >= nums[i]){
                q1.pop_back();
            }
            q1.push_back(i);
            while(!q2.empty() && nums[q2.back()] <= nums[i]){
                q2.pop_back();
            }
            q2.push_back(i);
            if(nums[q2.front()] - nums[q1.front()] <= limit){
                ans = max(ans, i - j + 1);
            }
            else if(q2.front() > q1.front()){
                j = q1.front() + 1;
                q1.pop_front();
            }
            else{
                j = q2.front() + 1;
                q2.pop_front();
            }
        }
        if(nums[q2.front()] - nums[q1.front()] <= limit){
            ans = max(ans, (int)nums.size() - j);
        }
        return ans;
    }
};
