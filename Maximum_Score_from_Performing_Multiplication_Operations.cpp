class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>& nums, vector<int>& multipliers,int l, int r, int i){
        if(i >= multipliers.size()){
            return 0;
        }
        if(l > r){
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int temp = 0;
        temp += max(helper(nums,multipliers,l+1,r,i+1) + nums[l]*multipliers[i], helper(nums,multipliers,l,r-1,i+1) + nums[r]*multipliers[i]);
        return dp[l][r] = temp;
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return helper(nums,multipliers,0,nums.size()-1,0);
    }
};
//worked in leetcode
class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>&a,vector<int>&mul,int i,int j,int n,int str,int m)
    {
        // base case
         if(m ==0 )return 0;
        if(i >j)return 0;

        if(dp[i][str] != 0)return dp[i][str];
       dp[i][str] =   max(a[i] *mul[str] + solve(a,mul,i+1,j,n,str+1,m-1) , a[j] * mul[str]            +solve(a,mul,i,j-1,n,str+1,m-1)) ;
        return dp[i][str];
    }
    int maximumScore(vector<int>& a, vector<int>& mul) {
        int m = mul.size();
        int n = a.size();
        memset(dp , 0,sizeof(dp));
        return solve(a,mul,0,n-1,n,0,m);
    }
};
