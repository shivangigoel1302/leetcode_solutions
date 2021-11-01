class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>>profit(costs.size());
        for(int i = 0; i < costs.size(); i++){
            profit[i] = {costs[i][0] - costs[i][1],i};
        }
        int cost = 0;
        int n = costs.size();
        sort(profit.begin(),profit.end());
        for(int i = 0; i <profit.size(); i++){
            if(i < n/2){
                 cost += costs[profit[i].second][0];
            }

            if(i >= n/2){
                cost += costs[profit[i].second][1];
            }
        }
        return cost;

    }
};
