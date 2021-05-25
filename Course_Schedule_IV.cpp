class Solution {
public:


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
       vector<int>adj[numCourses];

        vector<bool>ans(queries.size());
        vector<vector<bool>>visited(numCourses,vector<bool>(numCourses,false));
        vector<vector<bool>>reach(numCourses,vector<bool>(numCourses,false));
         for(auto i: prerequisites){
            adj[i[0]].push_back(i[1]);
            // visited[i[0]][i[1]] = true;
        }
        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            q.push(i);
            while(!q.empty()){
                int x = q.front();
                q.pop();
                //visited[i][x] = true;
                for(auto j : adj[x]){
                    if(visited[i][j]){
                        continue;
                    }
                    reach[i][j] = true;
                   visited[i][j] = true;
                    q.push(j);
                }
            }
        }
        for(int i = 0 ;i < queries.size(); i++){
            ans[i] = reach[queries[i][0]][queries[i][1]];
            // vector<bool>visited(numCourses,false);
            // ans[i] = dfs(adj,queries[i][0],queries[i][1],visited);
            // if(ans[i]){
            //     adj[queries[i][0]].push_back(queries[i][1]);
            // }
        }
        return ans;
    }
};
