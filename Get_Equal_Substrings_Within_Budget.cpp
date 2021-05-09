class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>diff(s.size(),0);
        for(int i = 0 ; i < s.size(); i++){
            diff[i] = abs(s[i]-t[i]);
        }
        int sum = 0;
        int left = 0;
        int ans= 0;
        for(int i = 0 ; i < s.size(); i++){
            sum += diff[i];
            while(sum > maxCost){
                sum -= diff[left++];
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};
