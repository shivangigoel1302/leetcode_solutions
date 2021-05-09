class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        for(auto i: knowledge){
            m[i[0]] = i[1];
        }
        string ans = "";
        for(int i = 0; i < s.size(); ){
            if(s[i] == '('){

                int j = i+1;
                while(j < s.size() && s[j] != ')'){
                    j++;

                }

                if(m.find(s.substr(i+1,j-i-1)) != m.end()){

                    ans += m[s.substr(i+1,j-i-1)];

                }
                else{
                    ans += "?";
                }
                i = j+1;
            }
            else{
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};
