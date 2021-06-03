class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>m;
        int count = 0;
        for(auto t: tasks){
            m[t]++;
            count = max(count,m[t]);
        }
        int ans = (count-1)*(n+1);
        for(auto i: m){
            if(i.second == count){
                ans++;
            }
        }
        return max((int)tasks.size(),ans);
    }
};
