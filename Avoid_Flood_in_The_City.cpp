class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int>dry;
        vector<int>ans(rains.size(),-1);
        unordered_map<int,int>m;
        for(int i = 0; i < rains.size(); i++){
            if(rains[i] > 0){
                if(m.count(rains[i])){
                    auto lptr = dry.lower_bound(m[rains[i]]);
                    if(lptr == dry.end()){
                        return {};
                    }
                    ans[*lptr] = rains[i];
                    dry.erase(lptr);
                    m[rains[i]] = i;
                }
                else{
                    m[rains[i]] = i;
                }
                ans[i] = -1;
            }
            else{
                dry.insert(i);
                ans[i] = 1;
            }
        }
        // auto it = dry.begin();
        // while(it != dry.end()){
        //     ans[*it] = 1;
        //     it++;
        // }
        return ans;
    }
};
