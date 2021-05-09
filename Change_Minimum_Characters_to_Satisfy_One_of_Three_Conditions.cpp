class Solution {
public:
    int strictless(vector<int>c1,vector<int>c2){
        int ans = INT_MAX;
        for(char c ='b'; c <='z';c++){
            int p = c - 'a';
            int left = accumulate(c1.begin()+p,c1.end(),0);
            int right = accumulate(c2.begin(),c2.begin()+p,0);
            ans= min(ans,left+right);
        }
        return ans;
    }
    int common(vector<int>c1,vector<int>c2){
        int ans = INT_MIN;
        for(int i = 0 ; i <26; i++){
            ans = max(ans,c1[i]+c2[i]);
        }
        return ans;
    }
    vector<int>get(string s){
        vector<int>chars(26,0);
        for(int i = 0; i < s.size(); i++){
            chars[s[i]-'a']++;
        }
        return chars;
    }
    int minCharacters(string a, string b) {
        auto c1 = get(a),c2 = get(b);
        int opt3 = a.size() + b.size() - common(c1,c2);
        return min(opt3,min(strictless(c1,c2),strictless(c2,c1)));
    }
};
