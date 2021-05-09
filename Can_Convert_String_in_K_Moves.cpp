class Solution {
public:
    bool canConvertString(string s, string t, int k) {
       vector<int>m(26,0);
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0 ; i < s.size(); i++){
            int diff = (t[i] - s[i] + 26)%26;
            if(diff > 0){
                m[diff] ++;
            }
        }
        for(int i = 0 ; i < m.size(); i++){
            int count = k/26 + (k%26 >= i);
            if(count < m[i]){
                return false;
            }
        }
        return true;
    }
};
