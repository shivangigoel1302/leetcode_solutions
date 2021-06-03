class Solution {
public:
    vector<int> count(string s){
        vector<int>temp(26,0);
        for(auto c: s){
            temp[c-'a']++;
        }
        return temp;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>counter(26,0);
        for(auto s: words2){
            vector<int>temp = count(s);
            for(int i = 0; i < 26; i++){
                counter[i] = max(counter[i],temp[i]);
            }
        }
        vector<string>ans;
        for(auto s : words1){
            vector<int>temp = count(s);
            int i = 0;
            while(i < 26){
                if(temp[i] < counter[i]){
                    break;
                }
                i++;
            }
            if(i == 26){
                ans.push_back(s);
            }
        }
        return ans;
    }
};
