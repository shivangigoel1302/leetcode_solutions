class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        shifts[shifts.size() - 1] = shifts[shifts.size() - 1]%26;
        for(int i = shifts.size()-2 ; i >=0 ; i --){
            shifts[i] = (shifts[i+1] + shifts[i]%26)%26;
        }
        string ans = "";
        int i = 0 ;
        while(i < shifts.size()){
            int ch = S[i];
            //cout<<(ch -'a' + shifts[i]+1)%26<<" ";
            int ascii =(ch -'a' + shifts[i])%26+ 97;
            char newch = (char)ascii;
            ans += newch;
            i++;
        }
        while(i < S.size()){
            ans += S[i];
            i++;
        }
        return ans;
    }
};
