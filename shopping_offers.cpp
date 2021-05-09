class Solution {
public:
    map<vector<int>,int>m;
    int getindividual(vector<int>price,vector<vector<int>>special,vector<int>needs){
        int sum = 0;
        for(int i = 0 ; i < needs.size(); i++){
            sum += price[i]*needs[i];
        }
        return sum;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = getindividual(price,special,needs);
        if(m.count(needs) >0){
            return m[needs];
        }
        for(int i = 0 ; i < special.size(); i++){
            vector<int>clone = needs;
            int j = 0;
            for( ; j < needs.size(); j++){
                int diff = clone[j]-special[i][j];
                if(diff < 0){
                    break;
                }
                clone[j] = clone[j]-special[i][j];
            }
            if(j == needs.size()){
                ans = min(ans,special[i][j] + shoppingOffers(price,special,clone));
            }
        }
        m[needs] = ans;
        return ans;
    }
};
