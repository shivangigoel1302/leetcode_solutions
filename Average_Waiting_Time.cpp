class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<long long >end(customers.size(),0);
        end[0] = customers[0][0] + customers[0][1];
        long long  wait = customers[0][1];
        for(int i = 1; i < customers.size(); i++){
            if(end[i-1] >= customers[i][0]){
                end[i] = end[i-1]+ customers[i][1];
            }
            else{
                end[i] = customers[i][0]+ customers[i][1];
            }
            wait += end[i] - customers[i][0];
        }
        double avg = wait/(customers.size()*1.0);
        return avg;
    }
};
