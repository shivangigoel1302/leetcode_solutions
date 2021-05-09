class Solution {
public:
    bool isanagram(vector<int>s_map,vector<int>p_map){
        for(int i = 0 ; i < 26; i++){
            if(s_map[i] != p_map[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(s.size() < p.size()) return ans;
        vector<int>s_map(26,0),p_map(26,0);
        for(int i = 0 ; i <p.size(); i++){
            s_map[s[i]-'a']++;
            p_map[p[i] - 'a']++;
        }
        int i = 0;
        for( i = 0 ; i < s.size() - p.size() ; i++){
            if(isanagram(s_map,p_map)){
                ans.push_back(i);
            }
            s_map[s[i + p.size()]-'a']++;
            s_map[s[i]-'a']--;
        }
        if(isanagram(s_map,p_map)){
            ans.push_back(i);
        }
        return ans;
    }
};
