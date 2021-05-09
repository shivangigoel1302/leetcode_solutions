class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int diffx=0;
        int diffy =0;
        for(int i =0 ; i < s1.size(); i++){
            if(s1[i] != s2[i] && s1[i] =='x'){
                diffx++;
            }
            else if(s1[i] != s2[i]){
                diffy++;
            }
        }
        int diff = diffx + diffy;
        if(diff%2 == 1){
            return -1;
        }
        if(diffx %2 == 0){
            return diff/2;
        }
        return diff/2 +1;
    }
};
