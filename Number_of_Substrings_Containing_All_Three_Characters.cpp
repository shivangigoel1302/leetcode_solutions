class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3]={0};
        int ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            count[s[i] - 'a'] = i+1;
            if(count[0] && count[1] && count[2]){
                ans += min(count[0],min(count[1],count[2]));
            }
        }
        return ans;
    }
};
