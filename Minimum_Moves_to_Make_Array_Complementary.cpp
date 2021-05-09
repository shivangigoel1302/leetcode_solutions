class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int>v(2*limit+2);
        int n = nums.size();
        for(int i = 0 ; i < n/2; i++){
            v[0]+=2;
            v[min(nums[i] + 1, 1+ nums[n-i-1])] -=1;
            v[max(nums[i] + limit, limit + nums[n-i-1]) + 1] += 1;
            v[nums[i] + nums[n-i-1]] -=1;
            v[nums[i] + nums[n-i-1] + 1] +=1;
        }
        int ans = nums.size();
        int curr = 0;
        for(int i = 0 ; i < 2*limit+2; i++){
            curr+= v[i];
            ans = min(ans,curr);
        }
        return ans;
    }
};
