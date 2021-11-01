class Solution {
public:
    struct subtreeinfo{
        int depth;
        int diameter;
        subtreeinfo(int d,int dia){
            depth = d;
            diameter = dia;
        }
    };
    vector<subtreeinfo>dfs(int idx,vector<int>&result,vector<int>adj[],vector<bool>&visited){
        vector<subtreeinfo>subtree;
        subtree.push_back(subtreeinfo(0,0));
        visited[idx] = true;
        for(auto i : adj[idx]){

            if(visited[i]){
                continue;
            }
            int num = subtree.size();
            auto childsubtree = dfs(i,result,adj,visited);
            for(auto &child: childsubtree){
                for(int j = 0; j < num ; j++){
                    auto tree = subtree[j];
                    subtreeinfo newsubtree(-1,-1);
                    newsubtree.depth = max(tree.depth,child.depth+1);
                    newsubtree.diameter = max(tree.diameter,max(tree.depth+child.depth + 1,child.diameter));
                    result[newsubtree.diameter-1]++;

                    subtree.push_back(newsubtree);
                }
            }
        }
        return subtree;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int>adj[n+1];
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>result(n-1,0);
         vector<bool>visited(n+1,false);
        dfs(1,result,adj,visited);
        return result;
    }
};
