class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int,int>freq;
        bool once = false;
        int ones = 0;
        int max_freq = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size(); i++){
            freq[nums[i]]++;
            int f = freq[nums[i]];
            if(f > max_freq){
                once = true;
                max_freq = f;
            }
            else if(f == max_freq){
                once = false;
            }
            if(f == 1){
                ones++;
            }
            else if(f == 2){
                ones--;
            }
            auto s = freq.size();
            if((max_freq*(s-1) == i && ones > 0 ) || (s*(max_freq - 1) == i && once)){
                ans = i+1;
            }
        }
        return ans;
    }
};
