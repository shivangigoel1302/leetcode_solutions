class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int eaten = 0;
        int day = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        while(day < days.size() || !pq.empty()){
            if( day < days.size() && apples[day] > 0 ){
                pq.push({day + days[day],apples[day]});
            }
            while(!pq.empty()){
                auto t = pq.top();
                pq.pop();
                if(t.second == 0 || t.first <= day){
                    continue;
                }
                eaten++;
                if(t.second > 1){
                    pq.push({t.first,t.second-1});
                }
                break;
            }
            day++;
        }
        return eaten;
    }
};
