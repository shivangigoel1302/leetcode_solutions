class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>m;
        int start = 0;
        int maxcount = 0;
        int maxlength = 0;
        for(int end = 0; end < s.size(); end++){
            char left = s[end];
            m[left] ++;
            maxcount = max(maxcount,m[left]);
            if(end-start + 1 - maxcount > k){
                char right = s[start];
                m[right]--;
                start++;
            }
            maxlength = max(maxlength, end-start+1);
        }
        return maxlength;
    }
};
