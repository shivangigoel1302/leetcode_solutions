class Solution {
public:
    int numSplits(string s) {
        map<char,int>m;
        set<int>st;
        for(int i = 0 ; i <s.size(); i++){
            m[s[i]] = i;
            st.insert(s[i]);
        }
        int distinct = st.size();
        set<char>container;
        int ans =0;
        container.insert(s[0]);
        for(int i = 1 ; i < s.size(); i++){
            int remaining = distinct - container.size();
            for(auto c : container){
                if(m[c] >= i){
                    remaining++;
                }
            }
            if(remaining == container.size()){
                ans++;
            }
            container.insert(s[i]);
        }
        return ans;
    }
};
