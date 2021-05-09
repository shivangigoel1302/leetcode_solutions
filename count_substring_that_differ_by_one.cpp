class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>>common(m+1,vector<int>(n+1));
        vector<vector<int>>different(m+1,vector<int>(n+1));
        int ans = 0;
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <=n ; j++){
                if(s[i-1] == t[j-1]){
                    common[i][j] = common[i-1][j-1] +1;
                    different[i][j] = different[i-1][j-1];
                }
                else{
                    different[i][j] = common[i-1][j-1] +1;
                }
                ans += different[i][j];
            }
        }
        return ans;
    }
};
