class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int sum = 0;
        int ans = INT_MAX;
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0 ; i < n; i++){
            sum += nums[i];
            if(sum >= k){
                ans = min(ans,i+1);
            }
            while(!pq.empty() && sum - pq.top().first >= k){
                ans = min(ans,i-pq.top().second);
                pq.pop();
            }
            pq.push({sum,i});
        }
        return ans == INT_MAX ?-1 :ans;
    }
};
