class Solution {
public:
    int uniqueLetterString(string s) {
        int ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            int left = 1;
            int right = 1;
            int l = i-1,r=i+1;
            while(l >= 0 && s[l] != s[i]){
                l--;
                left++;
            }
            while(r < s.size() && s[r] != s[i]){
                r++;
                right++;
            }
            ans += left*right;
        }
        return ans;
    }
};
