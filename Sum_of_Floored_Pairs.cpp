class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        int sz = 0;
        int mod = 1e9+7;
        for(int i = 0; i < n; i++){
            sz = max(sz,nums[i]);
        }
        vector<int>freq(sz+1,0);
        for(int i = 0;i < n; i++){
            freq[nums[i]]++;
        }
        for(int i = 1; i < sz+1; i++){
            freq[i] += freq[i-1];
        }
        unordered_map<int,int>m;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            if(m.count(num)){
                ans = (ans + m[num])%mod;
                continue;
            }
            int prev = num-1;
            int temp = 0;
            for(int j = 2; j; j++){
                int curr = num * j;
                curr = min(curr-1,sz);
                temp += (freq[curr] - freq[prev])*(j-1);
                temp %= mod;
                prev = curr;
                if(prev == sz){
                    break;
                }
            }
            ans = (ans+temp)%mod;
            m[num] = temp;
        }
        return ans;
    }
};
