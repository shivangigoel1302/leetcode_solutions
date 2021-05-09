class Solution {
public:
    int compress(vector<char>& chars) {

        string s="";
        for(int i = 0 ; i < chars.size();){
            int j = i;
            int count = 0;
            while(j< chars.size() && chars[i] == chars[j]){
                count++;
                j++;
            }

            s+=chars[i];
            if(count > 1){
                string cnt = to_string(count);
               s += cnt;

            }
            i = j;
        }
        for(int i = 0 ; i< s.size(); i++){
            chars[i] = s[i];
        }
        return s.size();
    }
};
