class Solution {
public:
    int bfs(vector<vector<int>>&forest,pair<int,int>start,int x,int y){
        queue<pair<int,int>>q;
        int xdir[4] = {1,0,-1,0};
        int ydir[4] = {0,1,0,-1};
        int n = forest.size();

        int m = forest[0].size();
        q.push({start.first,start.second});
        vector<vector<int>>visited(forest.size(),vector<int>(forest[0].size(),0));
        int step = 0;
        visited[start.first][start.second] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int xr = curr.first;
                int yr = curr.second;
                if(curr.first == x && curr.second == y){
                    return step;
                }
                for(int i = 0; i < 4; i++){
                int nr = xr + xdir[i];
                int nc = yr + ydir[i];
                if(nr >=0 && nc >= 0 && nr < n && nc < m &&forest[nr][nc] >= 1 && !visited[nr][nc]){
                    visited[nr][nc] = 1;
                    q.push({nr,nc});
                    }
                }
            }
            step++;
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int n = forest.size();

        int m = forest[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(forest[i][j] > 1){
                    pq.push({forest[i][j],i*m+j});
                }
            }
        }
        pair<int,int>start = {0,0};

        int ans = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int x = curr.second/m;
            int y = curr.second%m;
           int temp = bfs(forest,start,x,y);
            if(temp == -1){
                return -1;
            }
            ans += temp;
            start = {x,y};

        }
        return ans;
    }
};
