class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>reachable(n,false);
        vector<int>ans;
        for(auto e : edges){
            reachable[e[1]] = true;
        }
        for( int i = 0; i < n; i ++){
            if(!reachable[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};_
