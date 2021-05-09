class Solution {
public:
    bool checksubstr(string s, string t){
        int i = 0;
        int j = 0;
        while(j < t.size() && i < s.size()){
            if(t[j] == s[i]){
                j++;
                i++;
            }
            else{
                j++;
            }
        }
        if(i >= s.size()){
            return true;
        }
        return false;
    }
    string findLongestWord(string s, vector<string>& d) {

        int maxlen = 0;
        string ans = "";
        for(int i = 0 ; i < d.size(); i++){
            if(checksubstr(d[i],s)){
                if(d[i].size() > maxlen){
                    maxlen = d[i].size();
                    ans = d[i];
                }
                else if(d[i].size() == maxlen){
                    if(d[i] < ans){
                        ans = d[i];
                    }
                }
            }
        }
        return ans;
    }
};
