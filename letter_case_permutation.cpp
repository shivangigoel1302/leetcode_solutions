class Solution {
public:
    void helper(vector<string>& v, string &s,int i){
        if(i == s.size()){
            v.push_back(s);
            return;
        }
        if(s[i]< 48 || s[i] >57){
            char ch = tolower(s[i]);
            s = s.substr(0,i) + ch+ s.substr(i+1);
            helper(v,s,i+1);
            ch = toupper(ch);
            s = s.substr(0,i) + ch + s.substr(i+1);
            helper(v,s,i+1);
        }
        else{
            helper(v,s,i+1);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string>v;
        helper(v,S,0);
        return v;
    }
};
