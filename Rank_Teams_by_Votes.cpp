vector<vector<int>>v(26,vector<int>(26,0));
bool compare(char a, char b, int i){
    if(i >= 26){
        return a < b;
    }
    if(v[a-'A'][i] > v[b-'A'][i]){
        return true;
    }
    else if(v[a-'A'][i] < v[b-'A'][i]){
        return false;
    }
    return compare(a,b,i+1);
}
bool comp(char a,char b){
    return compare(a,b,0);
}
class Solution {
public:

    string rankTeams(vector<string>& votes) {
       for(int i = 0; i <26; i++){
           for(int j = 0; j < 26; j++){
               v[i][j] = 0;
           }
       }
        for(int i = 0; i < votes.size(); i++){
            for(int j = 0; j < votes[i].size(); j++){
                v[votes[i][j] - 'A'][j]++;
            }
        }
        sort(votes[0].begin(),votes[0].end(),comp);
        return votes[0];
    }
};
