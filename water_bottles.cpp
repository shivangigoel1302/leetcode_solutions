class Solution {
public:
    int helper(int numBottles, int numExchange, int empty){
        if(numBottles == 0){
            return 0;
        }
        int drinks = numBottles;
        empty += numBottles;
        drinks += helper(empty/numExchange,numExchange,empty%numExchange);
        return drinks;
    }
    int numWaterBottles(int numBottles, int numExchange) {
        return helper(numBottles,numExchange,0);
    }
};
