class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>m;
        for(int i = 0 ; i < paths.size(); i++){
            m[paths[i][0]] ++;
            if(m.find(paths[i][1]) == m.end()){
                m[paths[i][1]] = 0;
            }
        }
        for(auto city: m){
            if(city.second == 0){
                return city.first;
            }
        }
        return "";
    }
};
