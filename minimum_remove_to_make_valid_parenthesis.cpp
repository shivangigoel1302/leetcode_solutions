class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>p;
        set<int>indexclose;
        for(int i = 0 ; i < s.size(); i++){
            char c = s[i];
            if(c == '('){
                p.push({c,i});
            }
            else if(c == ')'){
                if(p.empty()){
                    indexclose.insert(i);
                }
                else{
                    p.pop();
                }
            }
        }
        while(!p.empty()){
            indexclose.insert(p.top().second);
            p.pop();
        }
        string ans = "";
        for(int i= 0 ; i < s.size(); i++){
            if(indexclose.find(i) == indexclose.end()){
                ans += s[i];
            }
        }
        return ans;

    }
};
