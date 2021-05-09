class Solution {
public:
    bool helper(vector<vector<char>>& board, string word,int i,int row,int col,vector<vector<bool>>&visited){
        if(row > board.size()-1| row < 0 || col < 0 || col > board[row].size()-1 || visited[row][col] == true){

            return false;
        }
        if(i == word.size()-1 && board[row][col] == word[i] ){
            return true;
        }
        if(board[row][col] == word[i]){
            visited[row][col] = true;
            bool op1 = helper(board,word,i+1,row,col+1,visited);
            bool op2 = helper(board,word,i+1,row,col-1,visited);
            bool op3 = helper(board,word, i+1, row+1, col,visited);
            bool op4= helper(board,word,i+1,row-1,col,visited);
            if(op1 || op2||op3|| op4){
                return true;
            }
            visited[row][col] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // bool visited[201][201]={false};
        vector<vector<bool>>visited(201, vector<bool> (201));
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[i].size(); j++){
                visited[i][j] = false;
            }
        }
        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[i].size(); j++){
                if(word[0] == board[i][j]){

                    if(helper(board,word,0,i,j,visited)){
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;

    }
};
