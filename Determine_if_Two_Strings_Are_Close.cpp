class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>w1(26,0),w2(26,0);
        vector<int>w3(26,0),w4(26,0);
        for(int i = 0;  i < word1.length(); i++){
            w1[word1[i] -'a']++;
            w2[word1[i] -'a'] = 1;
        }
        for(int i =0; i < word2.length(); i++){
            w3[word2[i] - 'a']++;
            w4[word2[i] - 'a'] = 1;
        }
        if(w2 != w4){
            return false;
        }
        sort(w1.begin(),w1.end());
        sort(w3.begin(),w3.end());
        return w1 == w3;
    }
};
