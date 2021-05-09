class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        map<int,int>m;
        for(auto i : coins){
            m[i]++;
        }
        int range = 0;
        for(auto it: m){
            if(range + 1 >= it.first){
                range += it.first*it.second;
            }
            else{
                return range+1;
            }
        }
        return range+1;
    }
};
