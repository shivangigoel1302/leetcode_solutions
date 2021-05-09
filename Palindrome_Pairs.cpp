class Solution {
public:
    //TRIE SOLUTION

//     class Solution {
// public:
//     // we will make a reverse trie because we always need to find a pair which is reverse of my current string. We need ordered pairs so we'll cut a string into two parts, left and remaining

//     /** a|bcd
//         ab|cd
//         abc|d
//         and then find 'left' in trie as trie already has reversed strings
//         but also make sure that your 'remaining' is a palindrome as well.
//         form the string like this left+rem+found

//         since we need ordered pairs
//         one more thing we can do is find 'remaining' in trie, make sure 'left' is a palindrome
//         and form the string like found + left + rem

//     */
//     struct TrieNode{
//         unordered_map<char,TrieNode*> child;

//         int index =-1;
//     }*root;

//     /** Inserts a word into the trie. */
//     void insert(string word, int idx) {
//         TrieNode*temp=root;

//         for(auto i: word){
//             // if there is no pointer to the character in the map then create new node
//             if(!temp->child.count(i)) temp->child[i]=new TrieNode();

//             // go to the child
//             temp=temp->child[i];
//         }

//         // fix the index as the current else it will be -1

//         temp->index= idx;
//         // cout<<temp->index<<endl;
//     }

//     /** Returns if the word is in the trie. */
//     int search(string word) {

//         // start search from root
//         TrieNode*temp=root;
//         for(auto i: word){
//             // if there is no pointer to the character then return -1
//             if(!temp->child.count(i)) return -1;
//             temp=temp->child[i];
//         }
//         // if we have traversed the whole string and still it is not a word in trie then return -1
//         return temp->index;
//     }

//     // check if a string is a palindrome
//     bool isPal(string&s){
//         int l = 0, r=s.size()-1;
//         while(l<=r){
//             if(s[l]==s[r]) l++,r--;
//             else return false;
//         }
//         return true;
//     }
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         // string a ="abcba";
//         // if(isPal(a)) return {{1}};
//         int n = words.size();

//         // initialise the root node
//         root=new TrieNode();

//         // insert all reversed words in trie
//         for(int i=0;i<n;i++){
//             string s = words[i];
//             reverse(s.begin(),s.end());

//             insert(s,i);
//         }
//         set<vector<int> > temp;
//         // lets start cutting
//         for(int i=0;i<n;i++){
//             for(int j=0;j<=words[i].size();j++){
//                 string left = words[i].substr(0,j), rem = words[i].substr(j);

//                 int idx = search(left);
//                 if(idx!=-1 && isPal(rem) && idx!=i){

//                    temp.insert({i,idx});
//                 }

//                 idx = search(rem);
//                 if(idx!=-1 && isPal(left) && idx!=i){

//                    temp.insert({idx,i});
//                 }
//             }
//         }
//         vector<vector<int>> ans;
//         for(auto i: temp){
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };


    bool palindrome(string s1,string s2){
        int i = 0;
        int j = s2.size()-1;
        while(i < s1.size() && j >= 0){
            if(s1[i] != s2[j]){
                return false;
            }
            i++;
            j--;
        }
        if(i == s1.size()){
            i = 0;
            while(i <= j){
                if(s2[i] != s2[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
        else if(j < 0){
            j = s1.size()-1;
            while(i <= j){
                if(s1[i] != s1[j]){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<char,vector<int>>ending;
        vector<vector<int>>ans;
        for(int i = 0 ; i < words.size(); i++){
            if(words[i] == ""){
                ending['-'].push_back(i);
                continue;
            }
            ending[words[i][words[i].size()-1]].push_back(i);
        }
        for(int i= 0 ; i < words.size(); i++){
            char c = words[i][0];
            for(auto w: ending[c]){
                if(i != w){
                    if(palindrome(words[i],words[w])){
                        ans.push_back({i,w});
                    }
                }
            }
            for(auto w : ending['-']){
                if(i != w && palindrome(words[i],words[i])){
                    ans.push_back({i,w});
                    ans.push_back({w,i});
                }
            }
        }
        return ans;
    }
};
