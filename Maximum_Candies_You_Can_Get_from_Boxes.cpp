class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_map<int,int>m;
        for(int i = 0; i < initialBoxes.size(); i++){
            m[initialBoxes[i]] = 1;
        }
        vector<int>visited(status.size(),0);
        string s = "";
        for(int i = 0; i < status.size(); i++){
            if(status[i] == 1){
                s += "1";
            }
            else{
                s += "0";
            }
        }
        int ans = 0;
        while(initialBoxes.size() > 0){
            int flag = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] == '1' && m.find(i) != m.end()){
                    flag = 1;
                    visited[i] = 1;
                    for(int j = 0; j < containedBoxes[i].size(); j++){
                        m[containedBoxes[i][j]] = 1;
                    }
                    for(int j = 0; j < keys[i].size(); j++){
                        s[keys[i][j]] = '1';
                    }
                    ans += candies[i];
                    m.erase(i);
                }
            }
            if(!flag){
                break;
            }
        }
        return ans;
    }
};
