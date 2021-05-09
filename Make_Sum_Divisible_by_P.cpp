class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       long long int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i< n; i++){
            sum += nums[i];
        }
        if(sum%p ==0) return 0;
        int ans = INT_MAX;
        int target = sum%p;
        unordered_map<int,int>m;
        m[0] = -1;
        sum = 0;
        for(int i = 0; i < n ;i++){
            sum += nums[i];
            m[sum%p] = i;
            if(m.find((sum%p-target+p)%p) != m.end()){
                ans = min(ans,i-m[(sum%p-target+p)%p]);
            }
        }
        if(ans == INT_MAX || ans == n) return -1;
        return ans;
    }
};
