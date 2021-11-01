class Solution {
public:
    int finddifference(vector<int>&toppings,int target,int i){
        if(target<=0 || i >= toppings.size()){
            return target;
        }
        else{
            int ans = INT_MAX;
            for(int j = 0; j <=2; j++){
                int temp = finddifference(toppings,target - j*toppings[i],i+1);
                if(abs(temp) < abs(ans)){
                    ans = temp;
                }
                else if(abs(temp) == abs(ans) && temp >= 0){
                    ans = temp;
                }
            }
            return ans;
        }
        return -1;
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = INT_MAX;
        int n = baseCosts.size();
        for(int i = 0; i < n; i++){
            target = target - baseCosts[i];
            int j = finddifference(toppingCosts,target,0);
            if(abs(j) < abs(ans)){
                ans = j;
            }
            else if(abs(j) == abs(ans) && j >= 0){
                ans = j;
            }
            target += baseCosts[i];
        }
        return target-ans;
    }
};
