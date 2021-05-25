class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<int>adj[numCourses];
        for(auto e : prerequisites){
            indegree[e[0]]++;
            adj[e[1]].push_back(e[0]);
        }
        queue<int>q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        if(q.size() == 0){
            return {};
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto j: adj[x]){
                if(indegree[j] == 0){
                    continue;
                }
                indegree[j]--;
                if(indegree[j] == 0){
                    q.push(j);
                }
            }
        }
       if(ans.size() == numCourses){
           return ans;
       }
        return {};
    }
};
