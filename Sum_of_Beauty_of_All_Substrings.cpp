class Solution {
public:
    int beauty(vector<int>freq){
        int maximum=INT_MIN,minimum = INT_MAX;
        for(int i = 0 ; i < 26; i++){
            if(freq[i] == 0) continue;
            maximum = max(maximum,freq[i]);
            minimum = min(minimum,freq[i]);
        }
        return maximum - minimum;
    }
    int beautySum(string s) {
        vector<int>freq(26,0);
        vector<int>n(26,0);
       int ans = 0;
        for(int i = 0 ; i < s.size()-1; i++){
            freq[s[i]-'a']++;
            for(int j = i+1; j < s.size(); j++){
                freq[s[j] - 'a']++;
                ans += beauty(freq);
            }
            freq = n;
        }
        return ans;
    }
};
