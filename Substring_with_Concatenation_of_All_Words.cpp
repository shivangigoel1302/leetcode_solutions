class Solution {
public:
    unordered_map<char,int>charmap(vector<string>words){
        unordered_map<char,int>m;
        for(int i = 0 ;i < words.size(); i++){
            for(char c : words[i]){
                m[c] ++;
            }
        }
        return m;
    }
    bool matches(unordered_map<char,int>curr,unordered_map<char,int>charCount){
        for(auto p : charCount){
            if(curr[p.first] != p.second){
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int nn = words[0].size();
        int concat = m*nn;
        vector<int>ans;
        if(n < concat){
            return ans;
        }

        unordered_map<char,int>charCount= charmap(words);
        unordered_map<string,int>wordCount;
        for(int i =0 ; i <words.size(); i++){
            wordCount[words[i]]++;
        }
        unordered_map<char,int>curr;
        for(int i = 0 ; i < concat ; i++){
            curr[s[i]]++;
        }
        for(int i = 0 ; i <= n-concat; i++){
            if(matches(curr,charCount)){
                bool flag = true;
                unordered_map<string,int>currword;
                for(int j = i ; j <i + concat; j+= nn){
                    currword[s.substr(j,nn)]++;

                    if(currword[s.substr(j,nn)] > wordCount[s.substr(j,nn)]){

                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ans.push_back(i);
                }
            }
            curr[s[i]]--;
            curr[s[i + concat]]++;
        }
        return ans;
    }
};
