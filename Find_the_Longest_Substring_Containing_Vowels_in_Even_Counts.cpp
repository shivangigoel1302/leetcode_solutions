class Solution {
public:
    int findTheLongestSubstring(string s) {
        string val  = "00000";
        map<char,int>m={{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
        if(s.size() == 1){
           if(m.find(s[0]) == m.end()){
                return 1;
            }
            return 0;
        }
        map<string,int>len;
      len[val] = -1;
        int ans = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(m.find(s[i]) != m.end()){
                if(val[m[s[i]]]=='0'){
                    val[m[s[i]]]='1';
                }
                else{
                    val[m[s[i]]]= '0';
                }
            }

             if(len.find(val) != len.end()){
                 ans = max(ans , i - len[val]);
             }
            else{
              len[val] = i;
            }
        }
        return ans;
    }
};
