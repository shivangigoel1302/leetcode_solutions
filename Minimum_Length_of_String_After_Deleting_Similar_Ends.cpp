class Solution {
public:
    int minimumLength(string s) {
        char last = ' ';
        int i = 0;
        int j = s.size()-1;
        while(i <= j){
            if(i == j){
                if(last == s[i]){
                    return 0;
                }
                return 1;
            }
            if(s[i] == s[j]){
                i++;
                j--;
                last = s[i-1];
            }
            else if(s[i] == last){
                i++;
                last = s[i-1];
            }
            else if(s[j] == last){

                j--;
                last = s[j+1];
            }
            else{
                break;
            }
        }
        return j-i+1;
    }
};
