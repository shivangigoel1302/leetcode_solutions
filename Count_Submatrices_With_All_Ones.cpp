class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int count =0;
        int r = mat.size();
        int c = mat[0].size();
        for(int i = 0 ; i < r; i++){
            for(int j = c-2; j >=0 ; j--){
                if(mat[i][j] == 1){
                    mat[i][j] += mat[i][j+1];
                }
            }
        }
        for(int i = 0 ; i< r ;i++){
            for(int j = 0 ; j < c; j++){
                int minwidth = mat[i][j];
                for(int k = i ; k < r; k++){
                    if(mat[k][j] == 0) break;
                    minwidth = min(minwidth, mat[k][j]);
                    count += minwidth;
                }
            }
        }
        return count;
    }
};
