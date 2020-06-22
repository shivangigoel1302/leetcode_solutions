#include<iostream>
using namespace std;
int flag=0;
void sum(int a[],int n,int pos,int value)
{
    for(int i=pos;i<n;i++)
    {

        int curr=value+a[i];
        if(curr==0)
        {
            flag=1;
        }
         sum(a,n,i+1,curr);
    }
}
int main()
{
    int t;
    int n;
    int a[1000];
    cin>>t;
    while(t>0)
    {


        cin>>n;

        for(int i=0;i<n;i++)
        {

            cin>>a[i];
        }
        t--;
    }
    sum(a,n,0,0);
    if(flag==1)
    {

        cout<<"yes";
    }
    else
    {

        cout<<"no";
    }
    return 0;
}
