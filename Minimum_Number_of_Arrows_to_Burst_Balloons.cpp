class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() <=1){
            return points.size();
        }
        sort(points.begin(),points.end());
        int count = 0;
        int boundary = points[0][1];
        for(int i = 0; i < points.size(); ){
            int j = i;
            while(j < points.size() && points[j][0] <= boundary){
                 boundary = min(boundary,points[j][1]);
                j+=1;

            }
            if(j < points.size()){
               boundary = points[j][1];
            }
            count++;
            i= j;
        }
        return count;
    }
};
