class Solution {
public:
    unordered_map<int,int>m;
    bool check(int p,vector<vector<int>>preferences,int partner){
        for(int i = 0; i < preferences[p].size() && preferences[p][i] != partner; i++){
            int next = m[preferences[p][i]];
            int curr = preferences[p][i];
            for(int j = 0; j < preferences[curr].size(); j++){
                if(preferences[curr][j] == p){
                    return true;
                }
                if(preferences[curr][j] == next){
                    break;
                }
            }
        }
        return false;
    }
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {

        for(int i = 0; i < pairs.size(); i++){
            m[pairs[i][0]] = pairs[i][1];
            m[pairs[i][1]] = pairs[i][0];
        }
        int unhappy = 0;
        for(int i = 0; i < pairs.size(); i++){
            int p1 = pairs[i][0];
            int p2 = pairs[i][1];
            if(check(p1,preferences,p2)) unhappy++;
            if(check(p2,preferences,p1)) unhappy++;
        }
        return unhappy;
    }
};
