class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int base = 0;
        for(int i = 0 ; i < tasks.size(); i++){
            base = max(base,tasks[i][1]);
        }
        int req = base;
        vector<pair<int,int>>v;
        for(int i = 0; i< tasks.size(); i++){
            v.push_back({tasks[i][1]-tasks[i][0],tasks[i][0]});
        }
        sort(v.begin(),v.end(),[](pair<int,int>p1,pair<int,int>p2){
            if(p1.first == p2.first){
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        });
        int i = 0;
        while(i < v.size()){
            if(base >= v[i].first + v[i].second){
                base -= v[i].second;
            }
            else{
                int r = v[i].first + v[i].second;
                req += r - base;
                base = v[i].first;
            }
            i++;
        }
        return req;
    }
};
