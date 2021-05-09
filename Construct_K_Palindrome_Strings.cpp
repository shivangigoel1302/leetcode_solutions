class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() < k) return 0;
        int alpha[26]= {0};
        for(int i = 0 ; i < s.size(); i++){
            alpha[s[i]-'a']++;
        }
        int ans = 0;
        for(int i = 0 ; i < 26; i++){
            ans += alpha[i]%2;
        }
        return ans <= k;
    }
};
