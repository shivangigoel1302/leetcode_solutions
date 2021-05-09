class Solution {
public:
    int repeatedStringMatch(string a, string b) {
          string s = a;
        if(b.size() <= a.size()){
            if(a.find(b) != string::npos){
                return 1;
            }
            a+=s;
            if(a.find(b) != string::npos){
                return 2;
            }
            return -1;
        }

        else{
            int repeat = b.size()/a.size() + (b.size() %a.size() ?1 :0);
            cout<<repeat<<" ";
            for(int i = 0 ; i < repeat-1; i++){
                a += s;
            }
            cout<<a<<" ";
            if(a.find(b) != string::npos){
                return repeat;
            }
            a += s;
            if(a.find(b) != string::npos){
                return repeat + 1;
            }
        }
        return -1;
    }
};
