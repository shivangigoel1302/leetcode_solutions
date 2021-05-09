class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int length = 0;
         int j = 0;
        for(int i = 0 ; i< s.size();){
            while(j< s.size() &&( m.find(s[j]) == m.end() || m[s[j]] == 0)){
                m[s[j]] ++;
                j++;
            }
            length = max(length, j-i);
            int k= i;
            for(; k < j && s[k] != s[j] ; k++){
               m[s[k]] --;
            }
            i = k+1;
            j++;
        }
        return length;
    }
};
