bool compare(pair<int,int>p1,pair<int,int>p2){
    if(p1.second!=p2.second) return p1.second > p2.second;
    return p1.first > p2.first;
}
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<pair<int,int>>v;
        for(auto hotel : restaurants){
            if(veganFriendly){
                if(hotel[2] && hotel[4] <= maxDistance  && hotel[3] <= maxPrice){
                    v.push_back({hotel[0],hotel[1]});
                }
            }
            else{
                if(hotel[4] <= maxDistance && hotel[3] <= maxPrice){
                    v.push_back({hotel[0],hotel[1]});
                }
            }
        }
        sort(v.begin(),v.end(),compare);
        vector<int>ans(v.size());
        for(int i = 0 ; i < v.size(); i++){
            ans[i] = v[i].first;
        }
        return ans;
    }
};
