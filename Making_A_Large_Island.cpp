class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,int index){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] != 1){
            return 0;
        }
        int ans = 1;
        grid[i][j] = index;
        ans += dfs(grid,i+1,j,index);
        ans += dfs(grid,i-1,j,index);
        ans += dfs(grid,i,j+1,index);
        ans += dfs(grid,i,j-1,index);
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>area(n*n+2,0);
        int index = 2;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    area[index] = dfs(grid,i,j,index);
                    ans = max(ans,area[index]);

                    index++;

                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int>s;
                    if(i+1 < n && grid[i+1][j] > 1){
                        s.insert(grid[i+1][j]);
                    }
                    if(i-1 >= 0 && grid[i-1][j] > 1){
                        s.insert(grid[i-1][j]);
                    }
                    if(j+1 < n && grid[i][j+1] > 1 ){
                        s.insert(grid[i][j+1]);
                    }
                    if(j-1 >= 0 && grid[i][j-1] > 1){

                        s.insert(grid[i][j-1]);
                    }
                    int temp =1;
                    auto it = s.begin();
                    while(it != s.end()){

                        temp += area[*it];
                        it++;
                    }
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};
