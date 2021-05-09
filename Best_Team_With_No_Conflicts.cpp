bool compare(pair<int,int>p1, pair<int,int>p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>score(scores.size());
        for(int i = 0 ; i < scores.size(); i++){
            score[i] = {scores[i],ages[i]};
        }
        sort(score.begin(),score.end(),compare);
        vector<int>l(scores.size(),0);
        int ans = 0;
        for(int i = 0 ; i < scores.size(); i++){
            l[i] = score[i].first;
            for(int j = 0 ; j < i ; j++){
                if(score[i].first >= score[j].first  && (l[i] < score[i].first + l[j])){
                    l[i] = score[i].first + l[j];

                }
            }
            ans = max(ans,l[i]);
        }
      return ans;
    }
};
