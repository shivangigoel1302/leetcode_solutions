class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        long long int n = k;
       vector<long long int>dp;
        dp.push_back(1);
        dp.push_back(1);
        long long int count = 0;
        for(int i = 2 ; dp.back() <= k ; i++){
            dp.push_back(dp[i-1]+dp[i-2]);
        }
        for(int i = dp.size()-1; i >=0; i--){
            if(k- dp[i] >=0) {
                k-=dp[i];
                count++;
            }
        }
        return count;
    }
};
