class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count = 0;
        int i;
        for( i = 0 ; i < costs.size(); i++){
            if(count + costs[i] > coins){
                break;
            }
            count += costs[i];
        }
        return i;
    }
};
