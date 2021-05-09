class Solution {
public:

    int minAreaRect(vector<vector<int>>& points) {

        int nMax = points.size();

        unordered_set<int> pointSet;

        for(int p=0;p<points.size(); p++){
            int x = points[p][0];
            int y = points[p][1];
            pointSet.insert(y + nMax*x);
        }

        int minArea = INT_MAX;
        for(int i=0;i<points.size();i++){

            int x0 = points[i][0];
            int y0 = points[i][1];

            for(int j=i+1;j<points.size();j++){

                int x1 = points[j][0];
                int y1 = points[j][1];

                if(x0 == x1 || y0 == y1) continue;

                bool hasCorner1 = pointSet.find(y0+nMax*x1) != pointSet.end();
                bool hasCorner2 = pointSet.find(y1+nMax*x0) != pointSet.end();

                if(hasCorner1 && hasCorner2){
                        int area = abs(y1-y0)*abs(x1-x0);
                        if(area > 0) minArea = min(minArea, area);
                }
            }

        }

	    return minArea ==  INT_MAX ? 0 : minArea;

    }
};
