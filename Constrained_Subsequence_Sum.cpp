class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        int ans = nums[0];
        for(int i = 0; i < nums.size(); i++){
            while(!pq.empty() && pq.top().second < i-k){
                pq.pop();
            }
            if(!pq.empty()){
                pq.push({max(nums[i],nums[i] + pq.top().first),i});
            }
            else{
                pq.push({nums[i],i});
            }
            ans = max(ans,pq.top().first);
        }
        return ans;
    }
};
