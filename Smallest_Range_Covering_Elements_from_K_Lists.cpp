class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n = nums.size();
        int high = INT_MIN;
        int low;
        for(int i = 0 ;i < n; i++){
            high = max(high,nums[i][0]);
            pq.push({nums[i][0],{i,0}});
        }
        low = pq.top().first;
        vector<int>v(2,0);
        v[0]=low;
        v[1]=high;
        while(pq.size()== n){
            auto t = pq.top();
            pq.pop();
            int r = t.second.first;
            int c = t.second.second;
            int val = t.first;
            if(c+1 < nums[r].size()){
                pq.push({nums[r][c+1],{r,c+1}});
                low = pq.top().first;
                high = max(high,nums[r][c+1]);
                if(high - low < v[1]-v[0]){
                    v[0]= low;
                    v[1] = high;
                }
            }
        }
        return v;
    }
};
