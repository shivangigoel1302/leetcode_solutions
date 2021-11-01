class Solution {
public:
    bool canvisit(int mid,vector<vector<int>>&cells,int row,int col){
        queue<pair<int,int>>q;
        vector<vector<int>>grid(row,vector<int>(col,0));
        for(int i = 0; i <= mid; i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        for(int i = 0; i < col; i++){
            if(grid[0][i] == 0){
                q.push({0,i});
                grid[0][i] = 1;
            }
        }
        vector<int>xdir{1,0,-1,0};
        vector<int>ydir{0,1,0,-1};
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x.first == row-1){
                return true;
            }
            for(int i = 0; i < 4; i++){
                int nr = x.first + xdir[i];
                int nc = x.second + ydir[i];
                 if(nr >= 0 && nc >=0 && nr < row && nc < col && !grid[nr][nc]){
                    q.push({nr,nc});
                    grid[nr][nc] = 1;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0,r = cells.size()-1;
        int ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            if(canvisit(mid,cells,row,col)){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return ans+1;
    }
};
