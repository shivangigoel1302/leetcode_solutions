class Solution {
public:
    int helper(vector<int>&nums,long long int sum,long long int S,int &count ,  int i, int dp[][2001] ){
        if(i == nums.size() && S == sum){
            count++;
            return 1;
        }
        if( i == nums.size()){
            return 0 ;
        }
        if(dp[i][sum+1000] != INT_MIN){
            return dp[i][sum+1000];
        }
       int add = helper(nums, sum - nums[i],S, count, i+1,dp);
       int sub = helper(nums, sum + nums[i],S, count, i+1,dp);
       dp[i][sum+1000] = add + sub;
       return dp[i][sum+1000];
    }
    int findTargetSumWays(vector<int>& nums,long long int S) {
        int count = 0 ;
        int dp[nums.size()][2001];
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < 2001 ; j++){
                dp[i][j] = INT_MIN;
            }
        }
        return helper(nums, 0,S, count, 0,dp);
        //return count;
    }
};
