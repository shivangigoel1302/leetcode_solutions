class Solution {
public:
    int helper(string text,int s,int e){
        if(s > e){
            return 0;
        }
        for(int i =s; i < e; i++){
            if(text.substr(s,i-s+1) == text.substr(e-i+s,i-s+1)){
                return 2 + helper(text,i+1,e - i + s -1);
            }
        }
        return 1;
    }
    int longestDecomposition(string text) {
        int n = text.size();
        return helper(text,0,n-1);
    }
};
