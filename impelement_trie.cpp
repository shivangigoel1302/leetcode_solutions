class Trie {
public:
    /** Initialize your data structure here. */
    set<string>s;
    set<string>::iterator iter;
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        s.insert(word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        for(iter = s.begin(); iter!= s.end(); iter++){
            if(iter->size() != word.size()){
                continue;
            }
            if(*iter == word){
                return true;
            }
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        for(iter = s.begin(); iter!= s.end(); iter++){
            if(iter->size() < prefix.size()){
                continue;
            }
            if(iter->substr(0,prefix.size()) == prefix){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
