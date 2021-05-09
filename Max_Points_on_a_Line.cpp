class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        if(points.size() <= 2){
            return points.size();
        }
        for(int i = 0 ; i < points.size()-1 ; i++){
            map<pair<int,int>,int>m;
            int same = 1;
            int count = 0;
            for(int j = i+1; j < points.size(); j++){
                int dx = points[j][0]-points[i][0];
                int dy = points[j][1]-points[i][1];
                if(dx == 0 && dy==0){
                    same++;
                    continue;
                }
                if(dx == 0){
                    dy = 1;
                }
                if(dy == 0){
                    dx = 1;
                }
                else{
                    int g = __gcd(dx,dy);
                    dx /= g;
                    dy /= g;
                }
                m[{dx,dy}] ++;
                count = max(count,m[{dx,dy}]);
            }
            ans = max(ans,count + same);
        }
        return ans;
    }
};
