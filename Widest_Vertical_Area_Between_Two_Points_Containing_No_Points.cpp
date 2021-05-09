class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int>s;
        for(auto it: points){
            s.insert(it[0]);
        }
        auto it = s.begin();
        int maxlen = 0;
        while(it != s.end()){
            int a = *it;
            it++;
            if(it != s.end()){
                int b = *it;
                maxlen = max(maxlen,b-a);
            }
        }
        return maxlen;
    }
};
