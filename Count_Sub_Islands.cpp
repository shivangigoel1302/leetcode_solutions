class Solution {
public:
    void dfs(vector<vector<int>>&grid2,vector<vector<int>>&grid1,bool &flag,int i,int j){
        if(i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size() || grid2[i][j] == 0){
            return;
        }
        if(grid1[i][j] == 0){
            flag = false;
        }
        grid2[i][j] = 0;
        dfs(grid2,grid1,flag,i+1,j);
        dfs(grid2,grid1,flag,i-1,j);
        dfs(grid2,grid1,flag,i,j+1);
        dfs(grid2,grid1,flag,i,j-1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int m = grid2.size();
        int n = grid2[0].size();
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1){
                    bool flag = true;
                    dfs(grid2,grid1,flag,i,j);
                    if(flag){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
