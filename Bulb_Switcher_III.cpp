class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ans = 0;
        int bulbs = 0;
        int maximum = 0;
        for(int i = 0 ; i < light.size(); i++){
            maximum = max(maximum, light[i]);
            bulbs++;
            if(maximum == bulbs){
                ans++;
            }
        }
        return ans;
    }
};
