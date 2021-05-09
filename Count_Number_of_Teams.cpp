class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for(int i = 1 ; i < rating.size()-1; i++){
            int ml = 0;
            int mr = 0;
            for(int j = i-1; j>=0 ; j--){
                if(rating[j] < rating[i]){
                    ml++;
                }
            }
            for(int j = i +1 ; j< rating.size(); j++){
                if(rating[j] < rating[i]){
                    mr++;
                }
            }
            ans += ml*(rating.size()-i-1-mr) + mr*(i - ml);
        }
        return ans;
    }
};
