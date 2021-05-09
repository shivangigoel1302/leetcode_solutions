class Solution {
public:
    int ans = 0;
    void clearisland(vector<vector<int>>&grid,int row,int col){
        if(row >= grid.size() || row < 0 || col <0 || col >= grid[0].size() || grid[row][col] == 1){
            return ;
        }
        grid[row][col] = 1;
        clearisland(grid,row+1,col);
        clearisland(grid,row-1,col);
        clearisland(grid,row,col+1);
        clearisland(grid,row,col-1);
        return;
    }

    int closedIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++){
            clearisland(grid,i,0);
        }
        for(int i = 0; i < grid[0].size(); i++){
            clearisland(grid,0,i);
        }
        for(int i = 0; i < grid.size(); i++){
            clearisland(grid,i,grid[0].size()-1);
        }
        for(int i = 0; i < grid[0].size(); i++){
            clearisland(grid,grid.size()-1,i);
        }
        for(int i = 1; i < grid.size()-1; i++){
            for(int j = 1; j < grid[0].size()-1 ; j++){
                if(grid[i][j] == 0){
                    ans++;
                    clearisland(grid,i,j);
                }

            }
        }
        return ans;
    }
};
