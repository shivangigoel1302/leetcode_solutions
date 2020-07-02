class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }
   map<int,vector<string>>m;
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int n=word.size();
        m[n].push_back(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool isequal(string key,string word)
    {
        for(int i=0;i<word.size();i++)
             {
                 if(word[i]=='.')
                    {
                        continue;
                    }
                  else if(word[i]!=key[i])
                  {
                      return false;
                  }
              }
        return true;
    }
    bool search(string word) {
        int n=word.size();
        if(m[n].size()==0)
        {
            return false;
        }

        for(auto it:m[n])
        {
            if(isequal(it,word))
            {
                return true;
            }
        }

        return false;

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
