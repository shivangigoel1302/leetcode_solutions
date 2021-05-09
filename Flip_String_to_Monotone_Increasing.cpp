class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int>p(S.size() + 1,0);
        for(int i = 0 ; i < n ; i++){
            p[i+1] = p[i] + (S[i] == '1' ? 1:0);
        }
        int ans = INT_MAX;
        for(int i = 0 ; i <=S.size(); i++){
            ans = min(ans,p[i] + n - i - (p[n] - p[i]));
        }
        return ans;
    }
};
