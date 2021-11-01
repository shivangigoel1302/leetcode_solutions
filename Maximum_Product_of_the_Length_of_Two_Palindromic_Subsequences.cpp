class Solution {
public:
    bool ispalindrome(string &s){
        int i = 0;
        int j = s.size()-1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void generatesubsequence(string &s,int &ans,int i,string &s1,string &s2){
        if(i >= s.size()){
            if(ispalindrome(s1) && ispalindrome(s2)){
               if(ans < s1.size() * s2.size()){
                   ans = s1.size()*s2.size();
               }
            }
            return;
        }
        s1 += s[i];
        generatesubsequence(s,ans,i+1,s1 ,s2);
        s1.pop_back();
        s2 += s[i];
        generatesubsequence(s,ans,i+1,s1,s2);
        s2.pop_back();
        generatesubsequence(s,ans,i+1,s1,s2);
    }
    int maxProduct(string s) {
        int ans = 0;
        string s1="",s2="";
        generatesubsequence(s,ans,0,s1,s2);
        return ans;
    }
};
