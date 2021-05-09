class Solution {
public:
    void sort(vector<vector<int>>&mat,int col,int row){
   int n = mat.size();
        for(int i = row +1,j = col+1; i <n && j <mat[0].size(); i++,j++){
            int key = mat[i][j];
            int pr = i-1;
            int pc = j-1;
            while(pr >=0 && pc >=0 && mat[pr][pc] > key){
                mat[pr+1][pc+1] = mat[pr][pc];
                pc--;
                pr--;
            }
            mat[pr+1][pc+1] = key;
        }
        return ;
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0 ; i < mat[0].size()-1; i++){
            sort(mat,i,0);
        }
        for(int i = 1; i  < mat.size()-1; i++){
            sort(mat,0,i);
        }
        return mat;
    }
};
