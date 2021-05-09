class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandy = INT_MIN;
        for(int i = 0 ; i< candies.size(); i++){
            if(candies[i] > maxcandy){
                maxcandy = candies[i];
            }
        }
        vector<bool>possible;
        for(int i = 0 ; i< candies.size(); i++){
            if(candies[i] +extraCandies < maxcandy){
                possible.push_back(false);
            }
            else{
                possible.push_back(true);
            }
        }
        return possible;
    }
};
