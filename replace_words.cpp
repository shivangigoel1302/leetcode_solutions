class Solution {
public:
    class trienode{
        public:
        trienode* m[26];
        string word;
        // trienode(){
        //     word ="";
        // }
    };
   trienode* getnode(char ch, trienode* curr){
      // cout<<curr->m[ch-'a'];
        if(curr->m[ch-'a'] ==  NULL){
            return NULL;
        }
        return curr->m[ch-'a'];
    }
    void insertintrie(trienode* &root,string word){
        if(root == NULL){
          trienode* n = new trienode();
            root = n;
            root->word = "";
        }
        trienode* curr = root;
        for(int i = 0 ; i < word.size(); i++){
            char ch = word[i];
           trienode* node = getnode(ch,curr);
            if(node == NULL){
                node=new trienode();
                curr->m[ch-'a'] =node;
            }
            curr = node;
        }
        curr->word = word;

    }
    string searchword(string iword, trienode* root){
        string ans = "";
        trienode* curr = root;
        for(int i = 0 ; i <iword.size(); i++){
            char ch = iword[i];
            //cout<<ch;
            trienode* node = getnode(ch,curr);
           // cout<<node->word;
            if(node == NULL ){
                return iword;
            }
            if(node->word.size() !=0){
                return node->word;
            }
            curr = node;
        }

        // if(curr->word.size()!=0){
        //     cout<<"dcsd";
        //     ans+=curr->word;
        //     return ans;
        // }
        return iword;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        trienode* root = NULL;
        for(auto word:dictionary){
            insertintrie(root,word);
        }
        string iword ="";
        string ans = "";
        for(int i = 0 ; i < sentence.size(); i++){
           if(i == sentence.size()-1){
               iword+=sentence[i];
               string s =  searchword(iword,root);
                //cout<<s<<",";
                ans+=s;
           }
            if(sentence[i] == ' '){
               string s =  searchword(iword,root);
                //cout<<s<<",";
                ans+=s;
                ans+= ' ';
                iword="";
            }
            else{
                iword+=sentence[i];
            }
        }
        return ans;
    }
};
