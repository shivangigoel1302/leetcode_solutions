class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int customer = 0;
        for(int i = 0 ; i  < customers.size(); i++){
            if(grumpy[i] == 0){
                customer += customers[i];
            }
        }
        int maxcus = 0;
        for(int i = 0 ; i < customers.size(); i++){
            if(grumpy[i] == 1){
                customer += customers[i];
            }
            if(i >= X && grumpy[i-X] == 1 ){
                customer -= customers[i-X];
            }
            maxcus = max(maxcus,customer);
        }
        return maxcus;
    }
};
