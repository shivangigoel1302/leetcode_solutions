class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<9;i++)
       {
           for(int j=0;j<9;j++)
           {
               if(board[i][j]=='.')
               {
                   continue;
               }
               for(int row=i+1;row<9;row++)
               {
                   if(board[row][j]!='.' && board[i][j]==board[row][j])
                   {
                       cout<<"h";
                       return false;
                   }
               }
               for(int col=j+1;col<9;col++)
               {
                   if(board[i][col]!='.' &&board[i][j]==board[i][col])
                   {

                       return false;
                   }
               }
            int r=(i/3)*3;
               int c=(j/3)*3;
               for(int row=r;row<r+3;row++)
               {
                   for(int col=c;col<c+3;col++)
                   {
                       if(row!=i&&col!=j&&board[i][j]==board[row][col]&&board[row][col]!='.')
                       {
                           cout<<"q";
                           return false;
                       }
                   }
               }
           }

       }
        return true;
    }
};
