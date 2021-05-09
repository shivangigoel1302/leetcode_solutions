class Solution {
public:
    int helper(vector<string>&words,vector<int>freq,vector<int>score, int i){
        if(i == words.size()){
            return 0;
        }
        int temp = helper(words,freq,score,i+1);
        string curr = words[i];
        int s = 0;
        int flag = 1;
        for(auto c: curr){
            if(freq[c-'a'] == 0){
                flag = 0;
            }
            freq[c-'a']--;
            s += score[c-'a'];
        }
        if(flag){
            temp = max(temp,s + helper(words,freq,score,i+1));
        }
        else{
            for(auto c: curr){
                freq[c-'a']++;
            }
        }
        return temp;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(auto c: letters){
            freq[c-'a']++;
        }

        return helper(words,freq,score,0);
    }
};
