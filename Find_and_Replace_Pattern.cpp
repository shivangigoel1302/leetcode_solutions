class Solution {
public:
    string convert(string w){
        map<char,int>m;
        int cur = 1;
        string x ="";
        for(int i = 0 ; i< w.size(); i++){
            if(m.find(w[i]) != m.end()){
                char c = m[w[i]] + '0';
                x += c;
            }
            else{
                char c = cur + '0';
                x += c;
                cur++;
                m[w[i]] = cur-1;
            }
        }

        return x;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string s = convert(pattern);
        vector<string>ans;
        for(int i = 0 ; i < words.size(); i++){
            string x = convert(words[i]);
            if(x == s){
               ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
