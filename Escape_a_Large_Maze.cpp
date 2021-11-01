class Solution {
public:
    unordered_set<long long>wall;
    bool valid(long long curr,unordered_set<long long>&visited){

        int n = 1e6;
        if(visited.find(curr) != visited.end() || wall.find(curr) != wall.end()){
            return false;
        }
        return true;
    }
    bool bfs(vector<int>&src,vector<int>tar){
        queue<long long>q;
        int n = 1e6;
        unordered_set<long long>visited;
        q.push((long long)src[0]*n + src[1]);
        while(!q.empty()){
            long long curr = q.front();
            q.pop();
            if(!valid(curr,visited)){
                continue;
            }
            int i = curr/n;
            int j = curr%n;
            if(i == tar[0] && j == tar[1]){
                return true;
            }
            if(i < n-1){
                q.push((long long)(i+1)*n + j);
            }
            if(j < n-1){
                q.push((long long)i*n + j + 1);
            }
            if(i > 0){
                q.push((long long)(i-1)*n + j);
            }
            if(j > 0){
                q.push((long long)i*n + j-1);
            }
            visited.insert(curr);
            if(visited.size() == 20000){
                return true;
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int n = 1e6;
        for(int i = 0; i < blocked.size(); i++){
            wall.insert((long long)blocked[i][0]*n + blocked[i][1]);
        }
        return bfs(source,target) && bfs(target,source);
    }
};
