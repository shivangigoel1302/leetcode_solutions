class Solution {
public:
    bool possible(string a,string b){
       bool zero = false;
       bool nonzero = false;
        if(a.size() == 1 && a[0] == '0'){
            zero = true;
        }
        else{
             for(int i = 0; i < a.size(); i++){
                if(a[i] != '0'){
                    nonzero = true;
                }
                else{
                    if(!nonzero){
                        return false;
                    }
                }
            }
        }
        if(b.size() == 0){
            return true;
        }
        if(zero){
            if(stoi(b) == 0){
                return false;
            }
        }
        nonzero = false;
        for(int i = b.size()-1; i>=0; i--){
            if(b[i] != '0'){
                nonzero = true;
            }
            else{
                if(!nonzero){
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> getpossibilities(string s){
        vector<string>temp;
        for(int i =1; i <= s.size(); i++){
            if(i < s.size()){
                if(possible(s.substr(0,i),s.substr(i))){
                    temp.push_back(s.substr(0,i) + '.' + s.substr(i));
                }
            }
            else{
                if(possible(s,"")){
                    temp.push_back(s);
                }
            }
        }
        return temp;
    }
    vector<string> ambiguousCoordinates(string s) {
        vector<string>ans;
        int n = s.size();
        for(int i = 1; i < s.size()-1; i++){
            string first = s.substr(1,i);
            string second = s.substr(i+1,n-i-2);

            vector<string>left = getpossibilities(first);
            vector<string>right = getpossibilities(second);
            for(auto x: left){
                for(auto y : right){
                    ans.push_back("(" + x + ", " + y + ")");
                }
            }
        }
        return ans;
    }
};
