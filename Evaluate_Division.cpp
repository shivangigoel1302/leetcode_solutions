class Solution {
public:
    double dfs(set<string>visited, string start, string end, double curr,map<string,vector<pair<string,double>>>m){
        if(m.find(start) == m.end() || m.find(end) == m.end()){
            return -1;
        }
        if(start == end){
            return curr;
        }
        visited.insert(start);
        for(auto p : m[start]){
            if(visited.find(p.first) == visited.end()){
                double k = dfs(visited, p.first, end, curr* p.second, m);
                if(k != -1){
                    return k;
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>>m;
        for(int i = 0 ;i < equations.size(); i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});

            m[equations[i][1]].push_back({equations[i][0],(1.0)/values[i]});
        }
        vector<double>ans;
        for(int i = 0 ; i < queries.size(); i++){
            set<string>visited;
            ans.push_back(dfs(visited,queries[i][0],queries[i][1],1,m));
        }
        return ans;
    }
};
