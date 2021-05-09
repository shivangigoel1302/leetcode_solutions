class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int,int>m;
        int maxfreq = 0;
        for(auto i: nums){
            m[i]++;
        }
        auto it = m.rbegin();
        while(it != m.rend()){
            int x = it->first;
            int curr = it->second;
            it++;
            m.erase(x);
            auto jt = it;
            int allowed = k;
            while(allowed && jt != m.rend()){
                int diff = x - jt->first;
                int a = allowed/diff;
                if(a == 0){
                    break;
                }
                int b = min(a,jt->second);
                allowed -= diff*b;
                curr += b;
                jt++;
            }
            maxfreq = max(maxfreq,curr);
        }
        return maxfreq;
    }
};
