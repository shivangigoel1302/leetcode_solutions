class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n));
        int num = 1;
        int r = 0;
        int c = 0;
        int rows = n;
        int cols = n;
        while(r < rows && c< cols){
            for(int i = c; i < cols ; i++){
                matrix[r][i] = num;
                num++;
            }
            r++;
            for(int i = r; i < rows; i++){
                matrix[i][cols-1] = num;
                num++;
            }
            cols--;
            if(r < rows){
                for(int i = cols-1 ; i>=c; i--){
                    matrix[rows-1][i] = num;
                    num++;
                }
                rows--;
            }
            if(c < cols){
                for(int i = rows-1; i>= r; i--){
                    matrix[i][c] = num;
                    num++;
                }
               c++;
            }
        }
        return matrix;
    }
};
