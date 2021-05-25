class Solution {
public:
    int lps(vector<vector<int>>&dp,string s){
         for (int len = 1; len <= s.size(); ++len)
        for (auto i = 0; i + len <= s.size(); ++i)
            dp[i][i + len] = s[i] == s[i + len - 1] ?
                dp[i + 1][i + len - 1] + (len == 1 ? 1 : 2) :
                    max(dp[i][i + len - 1],  dp[i + 1][i + len]);
    return dp[0][s.size()];
    }
    int longestPalindrome(string word1, string word2) {
        int sz = word1.size() + word2.size();
        string s = word1 + word2;
        vector<vector<int>>dp(sz+1,vector<int>(sz+1,0));
        lps(dp,s);
        int ans = 0;
        for(int i = 0; i < word1.size(); i++){
            for(int j = 0; j < word2.size(); j++){
                if(word1[i] == word2[j]){
                    ans = max(ans,dp[i][j+word1.size()+1]);
                }
            }
        }
        return ans;


//         map<char, int> mp;
//         for(int i=0; i<s1.size(); i++){
//             if(mp.count(s1[i])==0){
//                 mp[s1[i]]=i;
//             }
//         }
//         int ans=0;
//         map<char, bool> m;
//         reverse(s2.begin(), s2.end());
//         for(int i=0; i<s2.size(); i++){
//             if(mp.count(s2[i])!=0 && m[s2[i]]==false){
//                 m[s2[i]]=true;
//                 int id1=mp[s2[i]]+1;
//                 int id2=n-i-2;
//                 if(id1>=0 && id2>=0){
//                     ans=max(ans, 2+dp[id1][id2]);
//                 }
//             }
//         }
//         return ans;
    }
};
