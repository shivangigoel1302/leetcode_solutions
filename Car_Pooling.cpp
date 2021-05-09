class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int timestamp[1001] = {0};
        for(int i = 0 ; i < trips.size(); i++){
            timestamp[trips[i][1]] += trips[i][0];
            timestamp[trips[i][2]] -= trips[i][0];
        }
        int usedcapacity = 0;
        for(int i = 0 ; i < 1001; i++){
            usedcapacity += timestamp[i];
            if(usedcapacity > capacity){
                return false;
            }
        }
        return true;
    }
};
