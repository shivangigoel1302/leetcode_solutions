class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>>pq;
        for(int i = 0 ; i < points.size(); i++){
            int dist= points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if(pq.size() < k){
                pq.push({dist,i});
            }
            else{
                if(dist < pq.top().first){
                    pq.pop();
                    pq.push({dist,i});
                }
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            ans.push_back(points[x.second]);
        }
        return ans;
    }
};
