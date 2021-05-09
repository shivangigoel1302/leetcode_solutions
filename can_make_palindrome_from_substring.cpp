class Solution {
public:

    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<vector<int>>charcount(26,vector<int>(s.size() +1 , 0));
        for(int i = 0 ; i < s.size(); i++){
            for(int j = 0 ; j < 26 ; j++){
                if(s[i]-'a' == j){
                    charcount[j][i+1] = charcount[j][i] + 1;
                }
                else{
                    charcount[j][i+1] = charcount[j][i];
                }
            }
        }
        for(int i = 0 ; i < queries.size(); i++){
            int start = queries[i][0],end = queries[i][1]+1,changes = queries[i][2], odd = 0;
            for(int j = 0 ; j < 26 ; j++){
                odd +=( charcount[j][end] - charcount[j][start] )%2;
            }
            if(odd/2 <= changes){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
