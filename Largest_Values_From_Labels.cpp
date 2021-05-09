class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>m;
        int ans = 0;
        for(int i = 0 ; i < labels.size(); i++){
            pq.push({values[i],labels[i]});
        }
        while(!pq.empty() && num_wanted){
            auto x = pq.top();
            pq.pop();
            if(m[x.second] != use_limit){
                m[x.second]++;
                num_wanted--;
                ans += x.first;
            }
        }
        return ans;
    }
};
