class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<long long int,long long int>m;
        m[0] = 1;
       long long int mask = 0;
        long long int ans = 0;
        for(int i = 0; i < word.size(); i++){
            mask = mask ^(1 << (word[i]-'a'));
            if(m.count(mask)){
                ans += m[mask];
            }
            for(int j = 0; j < 10; j++){
                long long x = mask^(1 << j);
                if(m.count(x)){
                    ans += m[x];
                }
            }
            m[mask]++;
        }
        return ans;
    }
};
