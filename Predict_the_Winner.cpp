class Solution {
public:
    vector<vector<int>>dp;
    int findscore(vector<int>nums,int l , int r){
        if(l > r){
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int opt1 = nums[l] + min(findscore(nums,l+1,r-1), findscore(nums,l+2,r));
        int opt2 = nums[r] + min(findscore(nums,l+1,r-1),findscore(nums,l,r-2));
        return dp[l][r] = max(opt1,opt2);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i++){
            sum += nums[i];
        }
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        int score = findscore(nums,0,nums.size()-1);
        //cout<<score<<endl;
        int req = sum/2 + (sum%2 != 0);
        if(score >= req){
            return true;
        }
        return false;
    }
};
