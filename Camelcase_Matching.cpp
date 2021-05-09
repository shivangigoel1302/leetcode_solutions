class Solution {
public:
    bool check(string word,string pattern){
        int i =0;
        int j = 0;
        while(i < word.size() && j < pattern.size()){
            if(word[i] != pattern[j] && word[i] >= char(66) && word[i] <=char(90)){
                return false;
            }
            else if(word[i] != pattern[j]){
                i++;
            }
            else{
                j++;
                i++;
            }
        }
        if(j != pattern.size()){
            return false;
        }
        while(i < word.size()){
            if(word[i] >= char(65) && word[i] <= char(90)){
                return false;
            }
            i++;
        }
        return true;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>ans(queries.size());
        for(int i =0 ; i < queries.size(); i++){
            ans[i] = check(queries[i],pattern);
        }
        return ans;
    }
};
