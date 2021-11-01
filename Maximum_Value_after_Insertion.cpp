class Solution {
public:
    string maxValue(string n, int x) {
        char c = x+'0';

        if(n[0] == '-'){
            int i = 0;
            for(i = 0; i < n.size(); i++){
                if(n[i] > c){
                    break;
                }
            }
            string s = "";
            for(int j = 0; j < i; j++){
                s += n[j];
            }
            s += c;
            for(int j = i; j < n.size(); j++){
                s += n[j];
            }
            return s;
        }
        else{
            int i = 0;
            for(i = 0; i < n.size(); i++){
                if(n[i] < c){
                    break;
                }
            }
            string s = "";
            for(int j = 0; j < i; j++){
                s += n[j];
            }
            s += c;
            for(int j = i; j < n.size(); j++){
                s += n[j];
            }
            return s;
        }
        return n;
    }
};
