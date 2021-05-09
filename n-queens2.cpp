class Solution {
public:
    bool isValid(int i ,int j ,int n, vector<string>board){
        for(int row = 0 ; row < n; row++){
            if(board[row][j] == 'Q' && row!=i){
                return false;
            }
        }
        for(int col = 0 ; col < n; col++){
            if(board[i][col] == 'Q' && col!=j){
                return false;
            }
        }
        int row = i,col=j;
        while(row < n && col>=0){
            if(board[row][col] == 'Q' && row!=i && col!=j){
                return false;
            }
            row++;
            col--;
        }
        row = i;
        col= j;
        while(row >=0  && col < n){
            if(board[row][col] == 'Q' && row!=i && col!=j){
                return false;
            }
            row--;
            col++;
        }
        row = i;
        col= j;
        while(row<n && col < n){
            if(board[row][col] == 'Q' && row!=i && col!=j){
                return false;
            }
            row++;
            col++;
        }
         row = i;
        col= j;
        while(row>=0  && col >=0){
            if(board[row][col] == 'Q' && row!=i && col!=j){
                return false;
            }
            row--;
            col--;
        }
        return true;
    }
    bool helper(vector<string>&board,int n,int i,vector<vector<string>>&result){
        if(i == n){
            result.push_back(board);
            return true;
        }
        for(int j = 0 ; j < n ; j++){
            if(isValid(i,j,n,board)){
                board[i][j] = 'Q';
                bool nextPossible = helper(board,n,i+1,result);
                board[i][j] = '.';
            }
        }
        return false;
    }
    int totalNQueens(int n) {
        vector<string>board;
        for(int i = 0 ; i < n ; i++){
            string temp="";
            for(int j = 0 ; j < n  ;j ++){
               temp+=".";
            }
            board.push_back(temp);
        }
        vector<vector<string>>result;
        helper(board,n,0,result);
        return result.size();
    }
};

