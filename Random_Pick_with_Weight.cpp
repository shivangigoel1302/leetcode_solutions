class Solution {
public:
    vector<int>s;
    int total;
    Solution(vector<int>& w) {
        s= w;
        for(int i = 1; i < s.size(); i++){
            s[i] += s[i-1];
        }
        total = s[s.size()-1];
    }

    int pickIndex() {
        int idx = rand()%total;
        auto itr = upper_bound(s.begin(),s.end(),idx);
        return itr-s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
