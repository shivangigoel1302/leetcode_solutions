class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() == 0){
            return s.size() == 0;
        }
        bool first = (s.size() != 0 && (s[0] == p[0] || p[0] == '.'));
        if(p.size() >= 2 && p[1] == '*'){
            return (isMatch(s,p.substr(2)) || (first && isMatch(s.substr(1),p)));
        }
        else{
           return (first && isMatch(s.substr(1),p.substr(1)));
        }
        return false;
    }
};
