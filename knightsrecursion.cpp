#include<iostream>
using namespace std;
int row[8]={2,1,-1,-2,-2,-1,1,2};
int col[8]={1,2,2,1,-1,-2,-2,-1};
bool cango(int x,int y,int board[][10],int n)
{
    if(x<0||y<0||x>=n||y>=n)
    {
        return false;
    }
    if(board[x][y]!=-1)
    {
        return false;
    }
    return true;
}
bool knight(int board[][10],int x,int y,int n,int jump)
{
    if(jump==64)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int i=0;i<8;i++)
    {
        if(cango(x+row[i],y+col[i],board,n))
        {
            cout<<jump<<" ";
            board[x+row[i]][y+col[i]]=jump;
            jump++;
            bool nextpossible=knight(board,x+row[i],y+col[i],n,jump);
            if(nextpossible)
            {
                return true;
            }
            jump--;
            board[x+row[i]][y+col[i]]=-1;
        }
    }

}
int main(){
int n;
cin>>n;
int board[10][10];
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        board[i][j]=-1;
    }
}
board[0][0]=0;
knight(board,0,0,n,1);
}
