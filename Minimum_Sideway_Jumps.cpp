class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        bool lane[3];
        lane[0] = false;
        lane[1] = true;
        lane[2] = false;
        int pos=0,jump=0;
        while(pos < obstacles.size()){
            if(obstacles[pos] == 0){
                pos++;
                continue;
            }
            lane[obstacles[pos] - 1] = false;
            if(!lane[0] && !lane[1] && !lane[2]){
                pos -=1;
                jump+= 1;
                lane[0] = lane[1] = lane[2] = true;
                continue;
            }
            pos++;
        }
        return jump;
    }
};
