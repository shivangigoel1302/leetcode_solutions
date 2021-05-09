class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<char,int>char_count;
        map<string,int>string_count;
        int result = 0;
        for(int i = 0 ; i < minSize ; i++){
            char_count[s[i]]++;
        }
        if(char_count.size() <= maxLetters){
            string_count[s.substr(0,minSize)]++;
            result = max(result,string_count[s.substr(0,minSize)]);
        }
        for(int right = minSize ; right< s.size(); right++){
            char_count[s[right-minSize]]--;
            if(char_count[s[right-minSize]] == 0){
                char_count.erase(s[right-minSize]);
            }
            char_count[s[right]]++;
            if(char_count.size() <= maxLetters){
                string_count[s.substr(right-minSize+1,minSize)]++;
                result = max(result,string_count[s.substr(right-minSize+1,minSize)]);
            }
        }
        return result;
    }
};
