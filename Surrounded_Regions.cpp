class Solution {
public:
    int x[4] ={0,0,-1,1};
    int y[4] = {1,-1,0,0};
    void dfs(vector<vector<char>>&board, int i , int j){
        board[i][j] = 'E';
        for(int p = 0 ; p < 4 ; p++){
            int nr = i+x[p];
            int nc = j + y[p];
            if(nr >=0 && nr < board.size() && nc >=0 && nc < board[0].size() && board[nr][nc] == 'O'){
                dfs(board,nr,nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)return;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0 ; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(board,i,0);

            }
            if(board[i][n-1] == 'O'){
                dfs(board,i,n-1);
            }

        }
        for(int j = 0 ; j < n ; j++){
              if(board[0][j] == 'O'){
                dfs(board,0,j);

            }
            if(board[m-1][j] == 'O'){
                dfs(board,m-1,j);
            }
        }
        for(int i = 0 ; i < m ;i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 'E'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j]= 'X';
                }
            }
        }
        return;
    }
};
