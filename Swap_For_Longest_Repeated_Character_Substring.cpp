class Solution {
public:
    int maxRepOpt1(string text) {
        vector<vector<int>>temp(26);
        for(int i = 0; i < text.size(); i++){
            char x = text[i];
            temp[x-'a'].push_back(i);
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            int curr = 1,prev = 0,mx = 0;
            for(int j = 1;j < temp[i].size(); j++){
                if(temp[i][j] == temp[i][j-1] + 1){
                    curr++;
                }
                else{
                    if(temp[i][j] == temp[i][j-1] + 2){
                        prev = curr;
                    }
                    else{
                        prev = 0;
                    }
                    curr = 1;
                }
                mx = max(mx,curr+prev);
            }
            ans = max(ans,mx + ((int)temp[i].size() > mx ?1 : 0));
        }
        return ans;
    }
};
