class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq1;
        for(int i = 0 ; i < tasks.size(); i++){
            tasks[i].push_back(i);
            pq1.push(tasks[i]);
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq2;
        long long int curr = pq1.top()[0];
        while(!pq1.empty() && pq1.top()[0] == curr){
            pq2.push({pq1.top()[1],pq1.top()[2],pq1.top()[0]});
            pq1.pop();
        }
        vector<int>ans;
        while(!pq1.empty() || !pq2.empty()){
                curr += pq2.top()[0];

                ans.push_back(pq2.top()[1]);
                pq2.pop();
                if(pq2.empty() && !pq1.empty() && curr < pq1.top()[0]){
                    curr = pq1.top()[0];
                }
                while(!pq1.empty() && pq1.top()[0] <= curr){
                    pq2.push({pq1.top()[1],pq1.top()[2],pq1.top()[0]});

                    pq1.pop();
                }

        }
    return ans;
    }
};
