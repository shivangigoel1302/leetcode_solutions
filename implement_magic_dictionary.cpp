class MagicDictionary {
public:
    /** Initialize your data structure here. */
    vector<string>words;
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for(auto word:dictionary){
            words.push_back(word);
        }
    }
    int count(string w,string s){
        int change = 0;
        for(int i = 0 ; i < w.size(); i++){
            if(w[i] !=s[i]) change++;
            if(change > 1){
                return change;
            }
        }
        return change;
    }
    bool search(string searchWord) {
        for(auto word: words){
            if(word.size()!=searchWord.size()){
                continue;
            }
            else{
                if(count(word,searchWord) == 1){
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
