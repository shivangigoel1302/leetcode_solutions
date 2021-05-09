class Solution {
public:
    bool check(string word, vector<string>&wordDict){
        for(int i = 0 ; i < wordDict.size(); i++){
            if(wordDict[i].compare(word) == 0){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
       bool dp[100000]={false};
        dp[0] = true;
        for(int i =1 ; i <= s.size(); i++){
            if(!dp[i] && check(s.substr(0,i),wordDict)){
                dp[i] = true;
            }
            if(dp[i] == true){
                if(i==s.size()){
                    return true;
                }
                for(int j = i+1; j<=s.size(); j++){
                    if(!dp[j] && check(s.substr(i,j-i),wordDict)){
                        dp[j] = true;
                    }
                    if(j==s.size() &&dp[j] == true){
                        return true;
                    }
                }
            }
        }
        return false;

    }
};
