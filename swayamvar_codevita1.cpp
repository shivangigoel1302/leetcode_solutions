//This is The Coding Area
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string bride,groom;
  cin>>bride>>groom;
  queue<char>b;
  queue<char>g;
  if(n==0)
  {
      cout<<"0";
      return 0;
  }
  int bsize=bride.size();
  int gsize=groom.size();
  for(int i=0;i<bsize;i++)
  {
    b.push(bride[i]);
  }
  for(int i=0;i<gsize;i++)
  {
    g.push(groom[i]);
  }
  for(int i=0;i<n;i++)
  {
     if(b.front()==g.front())
     {
       b.pop();
       g.pop();
       n--;
       i--;
       continue;
     }
    else
    {
      int j=1;
      for(;j<n;j++)
      {
        char me=g.front();
        g.pop();
        g.push(me);
        if(b.front()==g.front())
        {
           b.pop();
          g.pop();
          n--;
          i--;
          break;
        }
      }
      if(j==n+1)
      {
        cout<<n;
        return 0;
      }
    }
  }
  cout<<n;
}
