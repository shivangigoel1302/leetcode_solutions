bool issafe(vector<vector<char>>& board,int num,int n,int i,int j)
{
    for(int k=0;k<n;k++)
    {
        if(board[i][k]==num+'0'||board[k][j]==num+'0')
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
            if(board[row][col]==num+'0')
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokusolver(vector<vector<char>>& board,int n,int i,int j)
{
    if(i==n)
    {
        return true;
    }
    if(j==n)
    {
        return sudokusolver(board,n,i+1,0);
    }
    if(board[i][j]!='.')
    {
        return sudokusolver(board,n,i,j+1);
    }
    for(int num=1;num<=9;num++)
    {
        if(issafe(board,num,n,i,j))
        {
            board[i][j]=num+'0';
            bool furthersafe=sudokusolver(board,n,i,j+1);
            if(furthersafe)
            {
                return true;
            }
            board[i][j]='.';
        }
    }
    return false;
}
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

       bool a= sudokusolver(board,9,0,0);
    }
};
