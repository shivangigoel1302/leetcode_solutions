class Solution {
public:
    string arrangeWords(string text) {
        map<int,vector<string>>m;
        string temp = "";
        text[0] = tolower(text[0]);
        for(int i = 0 ; i < text.size(); i++){
            if(text[i] == ' '){
                if(temp.size() != 0){
                    m[temp.size()].push_back(temp);
                    temp = "";
                }
            }
            else{
                temp += text[i];
            }
        }
        if(temp != ""){
            m[temp.size()].push_back(temp);
        }
        string output = "";
        for(auto i : m){
            for(auto v: i.second){
                output+= v;
                output+=" ";
            }
            //output+= " ";
        }
        output[0] = toupper(output[0]);
        output.erase(output.end()-1);
        return output;
    }
};
