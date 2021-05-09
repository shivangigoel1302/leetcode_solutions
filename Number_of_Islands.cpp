class Solution {
public:
   void clearisland(vector<vector<char>>&grid, int i , int j){
       if(i >=0 &&  i < grid.size() && j >=0 && j < grid[0].size() && grid[i][j] == '1'){
           grid[i][j] = '0';
           clearisland(grid,i+1,j);
           clearisland(grid,i-1,j);
           clearisland(grid,i,j+1);
           clearisland(grid,i,j-1);
       }
   }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0 ; j < grid[0].size(); j ++){
                if(grid[i][j] == '1'){
                    ans++;
                    clearisland(grid,i,j);
                }
            }
        }
        return ans;
    }
};
