class Solution {
public:
    vector<string> printVertically(string s) {
       int maxlen = 0;
        vector<string>word;
        string temp ="";
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == ' '){
                word.push_back(temp);
                maxlen = max(maxlen,(int)(temp.size()));
                temp = "";
            }

            else{
                temp += s[i];
            }
            if(i == s.size()-1){
                word.push_back(temp);
                maxlen = max(maxlen,(int)(temp.size()));
                temp = "";
            }
        }
        vector<string>vertical(maxlen,"");
        for(int i = 0 ; i < maxlen; i++){
            temp = "";
            for(int j = 0 ; j < (int)word.size(); j++){
                if(i < word[j].size()){
                    temp += word[j][i];
                }
                else{
                    temp += ' ';
                }
            }
            for(int k = temp.size()-1; k>=0 ; k--){
                if(temp[k] ==' '){
                    temp.erase(temp.begin() + k);
                }
                else{
                    break;
                }
            }
            vertical[i]=temp;
        }
        return vertical;
    }
};
