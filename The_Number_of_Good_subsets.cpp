class Solution {
public:
    unordered_map<int,int>m = {{2,0}, {3,1}, {5,2}, {7,3}, {11,4}, {13,5}, {17,6}, {19,7}, {23,8}, {29,9}};
        int mod = 1e9+7;
    int numberOfGoodSubsets(vector<int>& nums) {

        vector<long long int>v;
        for(int i = 0; i < nums.size(); i++){
           long long int num = nums[i];
            long long int mask = 0;
            if(num == 1){
                continue;
            }
            for(auto [j,bit] : m){
                if(num%j == 0){
                    num/=j;
                    mask = mask | (1 << bit);
                }
                if(num %j == 0){
                    mask = -1;
                    break;
                }
            }
            if(mask != -1){
                v.push_back(mask);
            }
        }

        int sz = v.size();
        vector<vector<long long int>>dp(sz+1,vector<long long int>(1024));
        for(int i = 0; i < 1024; i++){
            dp[sz][i] = 1;
        }
        for(int i = sz-1; i >= 0; i--){
            for(int j = 0;j < 1024; j++){
                dp[i][j] = dp[i+1][j];
                if((j &  v[i]) == 0){
                    dp[i][j] = (dp[i][j] + dp[i+1][j | v[i]])%mod;
                }
            }
        }
       long long int ans = dp[0][0] - 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                ans = (ans*2)%mod;
            }
        }
        return ans;
    }
};
