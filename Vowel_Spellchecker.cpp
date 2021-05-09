class Solution {
public:
    bool isvowel(char c){
        if( c== 'a' || c== 'e' || c=='i' || c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    string devowel(string word){
        string s = "";
        for(int i = 0; i < word.size(); i++){
            if(isvowel(word[i])){
                s +='*';
            }
            else{
                s += word[i];
            }
        }
        return s;
    }
    string lower(string word){
        string s = "";
        for(int i = 0 ; i < word.size(); i++){
            char c = tolower(word[i]);
            s+=c;
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,string>m1;
        unordered_map<string,string>m2;
        unordered_map<string,string>m3;
        for(int i = 0 ; i < wordlist.size(); i++){
            m1[wordlist[i]] = wordlist[i];
            string small = lower(wordlist[i]);
            if(m2.find(small) == m2.end()){
                m2[small] = wordlist[i];
            }

            string withoutv = devowel(small);
            if(m3.find(withoutv) == m3.end()){
                 m3[withoutv] = wordlist[i];
            }

        }
        vector<string>ans(queries.size());
        for(int i = 0 ; i < queries.size(); i++){

            if(m1.find(queries[i]) != m1.end()){

                ans[i] = m1[queries[i]];
                continue;
            }
            string small = lower(queries[i]);
            if(m2.find(small) != m2.end()){

                ans[i] = m2[small];
                continue;
            }
            string withoutv = devowel(small);
            if(m3.find(withoutv) != m3.end()){

                ans[i] = m3[withoutv];
                continue;
            }
            ans[i] = "";
        }
        return ans;
    }
};
