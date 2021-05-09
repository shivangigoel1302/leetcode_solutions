class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int curr = 0;
        int n = gas.size();
//         for(int i = 0 ; i < gas.size();){
//             curr = gas[i];
//             int init = i;
//             while(curr - cost[i] >= 0){
//                 curr -=cost[i];
//                 curr += gas[(i+1)%n];
//                 i = (i+1)%n;
//                 if(i == init){
//                    return init;
//                 }
//             }

//                 i = init+1;

//         }
//         return -1;
        int start = 0,remain=0,capacity=0;
        for(int i = 0 ; i < n; i++){
            capacity += gas[i] - cost[i];
            if(capacity < 0){
                remain += capacity;
                capacity = 0;
                start = i+1;
            }
        }
        if(remain + capacity < 0){
            return -1;
        }
        return start;
    }
};
