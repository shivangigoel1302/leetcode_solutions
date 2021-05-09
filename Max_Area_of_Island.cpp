class Solution {
public:
    int clearisland(vector<vector<int>>&grid, int i , int j){
        if(i >= 0 && i < grid.size() && j >=0 && j < grid[0].size() && grid[i][j] == 1){
            grid[i][j] = 0;
            int left = clearisland(grid,i,j-1);
            int right = clearisland(grid,i,j+1);
            int top = clearisland(grid,i-1,j);
            int bottom = clearisland(grid,i+1,j);
            return left + right+ bottom + top + 1;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1){
                    int temp = clearisland(grid,i,j);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};
