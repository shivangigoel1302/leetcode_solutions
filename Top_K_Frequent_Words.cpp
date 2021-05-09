class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>m;
        vector<string>ans(k);
        for(auto s: words){
            m[s]++;
        }
        map<int,vector<string>>mn;
        for(auto it: m){
            mn[it.second].push_back(it.first);
        }
        int i = 0;
        auto it = mn.rbegin();
        while(i < k && it!= mn.rend()){
            for(auto s: it->second){
                ans[i] = s;
                i++;
                if(i == k){
                    break;
                }
            }
            it++;
        }
        return ans;
    }
};
