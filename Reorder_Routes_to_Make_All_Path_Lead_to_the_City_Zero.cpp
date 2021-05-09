class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
       // int n = connections.size();
        vector<vector<int>>original(n),back(n);
        for(int i = 0; i < connections.size(); i++){
            original[connections[i][0]].push_back(connections[i][1]);
            back[connections[i][1]].push_back(connections[i][0]);
        }
        queue<int>q;
        q.push(0);
        int ans = 0;
        vector<bool>visited(n,false);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            visited[f] = true;
            for(auto i : original[f]){
                if(!visited[i]){
                    ans++;
                    q.push(i);
                }
            }
            for(auto i : back[f]){
                q.push(i);
            }
        }
        return ans;
    }
};
