class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        map<int,vector<int>>m;
        int maxday = 0;
        for(int i = 0 ; i < events.size(); i++){
            m[events[i][0]].push_back(events[i][1]);
            maxday = max(maxday,events[i][1]);
        }
        int count = 0;
        priority_queue<int, vector<int>,greater<int>>pq;
        int curday = 1;
        while(curday <= maxday){
            if(m.find(curday) != m.end()){
                vector<int> list = m[curday];
                for(auto l : list){
                    pq.push(l);
                }
            }
            while(!pq.empty() && pq.top() < curday){
                pq.pop();
            }
            if(pq.size() >0){
                pq.pop();
                count++;
            }
            curday++;
        }
        return count;
    }
};
