class Solution {
public:

    int waysToSplit(vector<int>& nums) {
        int mod = 1e9+7;
        int n = nums.size();
        vector<int>prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i < n ; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        int ans = 0;
        for(int i = 0 ; i < n-2 ; i++){
            auto lower = lower_bound(prefix.begin()+i+1,prefix.end(),2*prefix[i]);
            auto upper = upper_bound(prefix.begin()+i+1,prefix.end()-1,(prefix.back()+prefix[i])/2);
            if(upper > lower){
                ans = (ans + upper-lower)%mod;
            }
        }
        return ans%mod;
    }
};
