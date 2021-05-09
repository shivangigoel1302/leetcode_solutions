class Solution {
public:
    bool isPalindrome(string a , int i , int j){
        while(i <= j){
            if(a[i] != a[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool checkPalindromeFormation(string a, string b) {
        if(isPalindrome(a,0,a.length()-1))
        {
            return true;
        }
        if(isPalindrome(b,0,b.length()-1)){
            return true;
        }
        int end = b.size()-1;
        int i = 0;
        for(; i < a.length(); i++,end--){
            if(a[i] != b[end]){
                break;
            }
        }
        if(end == -1){
            return true;
        }
        if(isPalindrome(a,i,end)){
            return true;
        }
        if(isPalindrome(b,i,end)){
            return true;
        }
        end = a.size()-1;
        i= 0;
        for(; i < b.length(); i++,end--){
            if(b[i] != a[end]){
                break;
            }
        }
        if(end == -1){
            return true;
        }
         if(isPalindrome(a,i,end)){
            return true;
        }
        if(isPalindrome(b,i,end)){
            return true;
        }
        return false;
    }
};
