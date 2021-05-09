class Solution {
public:
    bool magic(int i , int j, vector<vector<int>>grid){
        int val[16]={0};
        for(int p = 0 ; p < 3 ; p ++){
            for(int q = 0 ; q < 3 ; q++){
                val[grid[p+i][q+j]]+=1;
            }
        }
        for(int p = 0 ; p  < 16; p++){
            if(val[p] >1 || val[0] !=0 ){
                return false;
            }
        }
       if(grid[i][j] + grid[i+1][j] + grid[i+2][j] !=15){
           return false;
       }

        if(grid[i][j] + grid[i][j+1] + grid[i][j+2] !=15){
           return false;
       }

        if(grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2] !=15){
           return false;
       }

         if(grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2] !=15){
           return false;
       }

        if(grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1] !=15){
           return false;
       }

        if(grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2] !=15){
           return false;
       }

        if(grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] !=15){
           return false;
       }

        if(grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] !=15){
           return false;
       }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r< 3 || c< 3){
            return 0;
        }
        int ans = 0;
        for(int i = 0 ; i < r-2; i++){
            for(int j = 0 ; j < c-2; j++){
                if(grid[i+1][j+1] != 5){
                    continue;
                }

                if(magic(i,j,grid)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
