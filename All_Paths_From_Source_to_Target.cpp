class Solution {
public:
    void dfs(vector<int>temp,vector<vector<int>>&ans,vector<vector<int>>&graph,vector<bool>visited,int src){
        visited[src] = true;
        temp.push_back(src);
        if(src == graph.size()-1){
            ans.push_back(temp);
            visited[src] = false;
            return;
        }
        for(auto nbr: graph[src]){
            if(!visited[nbr]){
                dfs(temp,ans,graph,visited,nbr);
            }
        }
        visited[src] = false;
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool>visited(graph.size(),false);
        vector<int>temp;
        vector<vector<int>>ans;
        dfs(temp,ans,graph,visited,0);
        return ans;
    }
};

// class Solution {
// public:
//     void dfs(vector<int>temp,vector<vector<int>>&ans,vector<vector<int>>&graph,vector<bool>visited,int src){
//         visited[src] = true;
//         temp.push_back(src);
//         if(src == graph.size()-1){
//             ans.push_back(temp);
//             visited[src] = false;
//             return;
//         }
//         for(auto nbr: graph[src]){
//             if(!visited[nbr]){
//                 dfs(temp,ans,graph,visited,nbr);
//             }
//         }
//        // visited[src] = false;
//         return;
//     }
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         vector<bool>visited(graph.size(),false);
//         vector<int>temp;
//         vector<vector<int>>ans;
//         dfs(temp,ans,graph,visited,0);
//         return ans;
//     }
// };
