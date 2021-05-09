class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
      if( N==1){
          return 1;
      }
        map<int, pair<int, int>> m;
        for(auto edges: trust){
            m[edges[1]].first++;
            m[edges[0]].second++;
        }
        for( auto it: m){
            if(it.second.first == N-1 && it.second.second == 0){
                return it.first;
            }
        }
        return -1;
    }
};
