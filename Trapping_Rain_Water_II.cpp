class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
      int m = heightMap.size();
      int n = heightMap[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    pq.push({heightMap[i][j],{i,j}});
                    visited[i][j] = true;
                }
            }
        }
        int sum = 0;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int val = x.first;
            int r = x.second.first;
            int c = x.second.second;
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if(nr >= 0 && nc >=0 && nr < m && nc < n && visited[nr][nc] == false){
                    visited[nr][nc] = true;
                    sum += max(0,val - heightMap[nr][nc]);
                    pq.push({max(val,heightMap[nr][nc]),{nr,nc}});
                }
            }
        }
        return sum;
    }
};
