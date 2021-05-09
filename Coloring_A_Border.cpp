class Solution {
public:
    bool check(vector<vector<int>>grid, int i,int j, int init,vector<vector<bool>>visited){
        bool op1 = false;
        if(i -1 >= 0 &&(grid[i-1][j] == init || visited[i-1][j]) ){
            op1 = true;
        }
        else {
            return true;
        }
        bool op2 = false;
        if(i + 1 < grid.size() && (grid[i+1][j] == init|| visited[i+1][j])){
            op2 = true;
        }
         else{
            return true;
        }
        bool op3 = false;
        if(j - 1 >=0 && (grid[i][j-1] == init || visited[i][j-1])){
            op3 = true;
        }
         else{
            return true;
        }
        bool op4 = false;
        if(j + 1 < grid[i].size() && (grid[i][j+1] == init || visited[i][j+1])){
            op4 = true;
        }
         else {
            return true;
        }
        return false;
    }
    void helper(vector<vector<int>>& grid, int r0, int c0, int color,int initial, vector<vector<bool>>&visited){
        if(r0 < 0 || r0 >= grid.size() || c0 < 0 || c0 >= grid[r0].size() || grid[r0][c0] != initial || visited[r0][c0]){
            return;
        }
        visited[r0][c0] = true;
        if(check(grid,r0,c0,initial,visited)){
            grid[r0][c0] = color;
        }
        helper(grid,r0+1,c0,color,initial,visited);
        helper(grid,r0-1,c0,color,initial,visited);
        helper(grid,r0,c0+1,color,initial,visited);
        helper(grid,r0,c0-1,color,initial,visited);
        return;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int initial = grid[r0][c0];
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        helper(grid,r0,c0,color,initial,visited);
        return grid;
    }
};
