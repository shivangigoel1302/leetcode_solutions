class Solution {
public:

    bool check(string word, string s){
        int i =0;
        int j = 0;
        while(i < word.size() && j < s.size()){
            if(s[j] == word[i]){
                i++;
            }
            j++;
        }
        if(i == word.size()){
            return true;
        }
        return false;
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        map<string,int>m;
        for(int i = 0 ; i < words.size(); i++){
            m[words[i]]++;
        }
        int count = 0;
        for(auto i : m){
            if(check(i.first,S)){
                count+= i.second;
            }
        }
        return count;
    }
};
