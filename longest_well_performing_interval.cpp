class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int presum = 0;
        int maxlen = 0;
        vector<int>dp={-1};
        for(int i = 0 ; i < hours.size(); i++){
            hours[i] = hours[i] > 8 ? 1: -1;
            presum += hours[i];
            if(presum > 0){
                maxlen = i+1;
            }
            else{
                if(dp.size() > -(presum-1)){
                    maxlen = max(maxlen, i - dp[-(presum-1)]);
                }
                if(dp.size() <= -presum){
                    dp.push_back(i);
                }
            }
        }
        return maxlen;
    }
};
