class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.size() == 0){
            return 0;
                         }
        int dp = 1;
        int ans = 0;
        vector<int>alpha(26,0);
        alpha[p[0] - 'a'] = 1;
        for(int i = 1 ; i < p.size(); i++){
            if(p[i] - 'a' == (p[i-1] -'a' + 1)%26){
                dp ++;
            }
            else{
                dp = 1;
            }
            alpha[p[i] -'a'] = max(alpha[p[i] - 'a'],dp);
        }
        for(int i = 0 ; i < 26; i++){
            ans += alpha[i];
        }
        return ans;
    }
};
