class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size() < 2){
            return "";
        }
        int s = 0;
        int e = palindrome.size()-1;
        while(s < e){
            if(palindrome[s] != 'a'){
                palindrome[s] = 'a';
                return palindrome;
            }
            s++;
            e--;
        }
        palindrome[palindrome.size()-1] = 'b';
        return palindrome;
    }
};
