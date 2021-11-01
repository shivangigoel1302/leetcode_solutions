class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long int>prefixsum(n,0);
        prefixsum[0] = candiesCount[0];
        for(int i =1 ; i< n; i++){
            prefixsum[i] += prefixsum[i-1] + candiesCount[i];
        }
        vector<bool>ans(queries.size(),true);
        for(int i = 0; i < queries.size(); i++){
            long long int candy = queries[i][0];
            long long int day = queries[i][1];
            long long int maxi = queries[i][2];
            if(prefixsum[candy] <= day){
                ans[i] = false;
            }
            else{
                if(candy > 0){
                    long long int minimum = prefixsum[candy-1]/maxi;
                    if(day >= minimum){
                        ans[i] = true;
                    }
                    else{
                        ans[i] = false;
                    }
                }
            }
        }
        return ans;
    }
};
