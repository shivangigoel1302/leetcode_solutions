class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double>time(n);
        for(int i = 0; i < n ; i++){
            time[i] = dist[i]/(speed[i]*1.0);
        }
        sort(time.begin(),time.end());
        int curr = 0,monster = 0;
        for(int i = 0; i < n; i++){
            if(curr < time[i]){
                monster++;
                curr++;
            }
            else{
                return monster;
            }
        }
       return monster;
    }
};
