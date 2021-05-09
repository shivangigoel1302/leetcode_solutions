class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>cars;
        if(position.size() == 0){
            return 0;
        }
        for(int i = 0 ; i < position.size(); i++){
            double time = (target - position[i])/double(speed[i]);
            cars.push_back({position[i],time});
        }
        int ans = 0;
        sort(cars.begin(),cars.end());
        for(int i = cars.size()-1; i>0 ; i--){
            if(cars[i].second < cars[i-1].second){
                ans++;
            }
            else{
                cars[i-1].second = cars[i].second;
            }
        }
        return ans+1;
    }
};
