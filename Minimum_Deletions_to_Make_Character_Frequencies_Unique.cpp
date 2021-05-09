class Solution {
public:
    int minDeletions(string s) {
        vector<int>fre(26,0);
        for(int i = 0 ; i < s.size(); i++){
            fre[s[i]-'a']++;
        }
        map<int,int>m;
        for(int i = 0; i < 26; i++){
            m[fre[i]]++;
        }
        int ans = 0;
        for(auto it = m.rbegin(); it != m.rend(); it++){
            int fre = it->first;
            int count = it->second;
            if(fre == 0 || count == 1){
                continue;
            }
            int new_count = count -1;
            m[fre-1] += new_count;
            ans += new_count;
        }
        return ans;
    }
};
