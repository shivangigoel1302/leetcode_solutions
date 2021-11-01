class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n,'a');
        int i = n-1;
        while(k > 0){
            int a = min(26,k-n+1);
            char c = a-1+'a';
            s[i] = c;
            k -= a;
            n--;
            i--;
        }
        return s;
    }
};
