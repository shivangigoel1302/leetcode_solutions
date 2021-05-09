class Solution {
public:
    int bitmask(string w){
        int mask = 0;
            for(auto c : w){
                int bit = c - 'a';
                mask |= (1<<bit);
            }
        return mask;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<char,vector<int>>m;
        for(auto w : words){
            int mask = bitmask(w);
            vector<bool>visited(26,false);
            for(auto c: w){
                if(!visited[c-'a']){
                     m[c].push_back(mask);
                    visited[c-'a'] = true;
                }
            }
        }
        vector<int>ans;
        for(auto w:puzzles){
            char c = w[0];
            int mask = bitmask(w);
            int count = 0;
            for(auto it: m[c]){
                if((it & mask) == it){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
