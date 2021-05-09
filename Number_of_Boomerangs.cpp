class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 0 ; i < points.size(); i++){
            map<int,int>m;
            for(int j = 0 ; j < points.size(); j++){
                if(j != i){
                    int dx = points[j][0] - points[i][0];
                    int dy = points[j][1] - points[i][1];
                    int dist = dx*dx + dy*dy;
                    m[dist]++;
                }
            }
            for(auto it: m){
                ans += (it.second*(it.second - 1));
            }
        }
        return ans;
    }
};
