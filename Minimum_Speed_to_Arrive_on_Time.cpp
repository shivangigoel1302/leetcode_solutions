class Solution {
public:
    bool ispossible(int mid,double hour,vector<int>dist){
        double curr = 0;
        for(int i = 0; i < dist.size()-1; i++){
            int time = (dist[i]+mid-1)/mid;
            curr += time;
        }
        curr += (dist.back()/(mid*1.0));
        return curr <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1,r = 1e7;
        if(hour < (double)(dist.size()-1)){
            return -1;
        }
        while(l < r){
            int mid = (l + r)/2;
            if(ispossible(mid,hour,dist)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return r;
    }
};
