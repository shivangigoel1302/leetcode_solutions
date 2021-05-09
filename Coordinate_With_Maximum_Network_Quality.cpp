class Solution {
public:

    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
       pair<int,int> res;
        int bestQ = 0;
        for(int x1 = 0;x1<=50;x1++) for(int y1=0;y1<=50;y1++){
            int sumQ = 0;
            for(const auto& t2:towers){
                const int x2 = t2[0], y2 = t2[1], q = t2[2];
                int r2 = pow(x1-x2, 2) + pow(y1-y2, 2);
                if(r2 > radius*radius) continue;
                sumQ += int(q/(1+sqrt(r2)));
            }
            if(sumQ > bestQ){
                bestQ = sumQ;
                res = pair{x1, y1};
            }
            else if(sumQ == bestQ){
                res = min(res, pair{x1, y1});
            }
        }
        return vector<int>{{res.first, res.second}};
    }
};
