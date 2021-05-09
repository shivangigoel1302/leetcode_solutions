class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int len = 0;
        int i = 0;
        int start = 0;
        map<char,int>m;
        m['a'] = 0;
        m['e'] = 1;
        m['i'] = 2;
        m['o'] = 3;
        m['u'] = 4;
        int p = -1;
        vector<bool>chars(5,false);
        while(i < word.size()){
            if(chars[m[word[i]]] == false && m[word[i]] == p+1){
                chars[m[word[i]]] = true;
                p++;
            }
            else if(chars[m[word[i]]] == true && m[word[i]] == p){

            }
            else{
                if(p == 4 && i - start > len){
                    len = i - start;
                }
                //len = max(len,i-start);
                //cout<<start<<" "<<i<<endl;
                p = -1;
                for(int j = 0 ; j < 5; j++){
                    chars[j] = false;
                }
                if(i-start != 0){
                    start = i;
                    i--;
                }
                else{
                    start = i+1;
                }
            }
            i++;
        }
        if(p == 4 && i - start > len){
                    len = i - start;
        }
        return len;
    }
};
