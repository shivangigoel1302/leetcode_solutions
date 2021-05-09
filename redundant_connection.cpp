class Solution {
public:
    int getparent(int v, vector<int>parent){
        if(parent[v] == v){
            return v;
        }
        return getparent(parent[v],parent);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(edges.size()+1);
        for(int i = 1 ; i <= edges.size(); i++){
            parent[i] = i;
        }
        vector<int>ans;
        for(int i = 0 ; i < edges.size(); i++){
            int src = edges[i][0];
            int dest = edges[i][1];
            int srcparent= getparent(src,parent);
            int destparent = getparent(dest,parent);
            if(srcparent != destparent){
               parent[srcparent] = destparent;
            }
            else{
                ans.clear();
                ans.push_back(src);
                ans.push_back(dest);
            }
        }
        return ans;
    }
};
