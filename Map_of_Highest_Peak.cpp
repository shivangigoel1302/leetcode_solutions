class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MIN));
        queue<int>q;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(isWater[i][j] == 1){
                     q.push(i*(m+1) + j);
                     dist[i][j] = 0;
                }
            }
        }
        int xdir[4] = {0,0,1,-1};
        int ydir[4] = {-1,1,0,0};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = x/(m+1) + xdir[i];
                    int nc = x%(m+1) + ydir[i];
                    if(nr >=0 && nr < n && nc>=0 && nc < m && dist[nr][nc] == INT_MIN){
                        dist[nr][nc] = dist[x/(m+1)][x%(m+1)] + 1;
                        q.push(nr*(m+1) + nc);
                    }
                }
            }
        }
        return dist;
    }
};
