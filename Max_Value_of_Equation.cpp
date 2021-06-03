class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        int maximum = INT_MIN;
        for(int i = 0; i < points.size(); i++){
            while(!pq.empty() && abs(pq.top().second - points[i][0]) > k){
                pq.pop();
            }
            if(!pq.empty()){
                maximum = max(maximum, abs(pq.top().second - points[i][0]) + (pq.top().second + pq.top().first) + points[i][1]);
            }
            pq.push({points[i][1] - points[i][0],points[i][0]});
        }
        return maximum;
    }
};
