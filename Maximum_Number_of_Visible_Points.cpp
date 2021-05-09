class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        double PI = 3.141592653;
        double angleRad = angle * 2 * PI / 360;
        vector<double> pointsRad;
        int res = 0, n = (int)points.size();
        for (int i = 0; i < n; i++) {
            if (points[i][0] == location[0] && points[i][1] == location[1]) {
                res++;
                continue;
            }
            pointsRad.push_back(atan2(points[i][1] - location[1], points[i][0] - location[0]));
        }
        if (!pointsRad.size()) return res;
        sort(pointsRad.begin(), pointsRad.end());
        int cur = 0;
        while (pointsRad[cur] < 0) {
            pointsRad.push_back(2 * PI + pointsRad[cur]);
            cur++;
        }
        if (!pointsRad.size()) return res;
        int left = 0, maxCur = 0;
        for (int i = 0; i < pointsRad.size(); i++) {
            while (pointsRad[i] - pointsRad[left] > angleRad)  left++;
            maxCur = max(maxCur, i - left + 1);
        }
        res += maxCur;
        return res;
    }
};
