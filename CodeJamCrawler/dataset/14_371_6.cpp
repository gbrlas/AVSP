#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    freopen("c1.in", "r", stdin);
    freopen("c2.out", "w", stdout);

    int t;
    cin>>t;
    int r1;
    int a[4][4];
    int b[4][4];
    int r2;

    for(int k=0;k<t;k++)
    {
        int num[4];
        for(int i=0;i<4;i++)
        {
            num[i]=0;
        }
    int m=0;
    cin>>r1;
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    cin>>a[i][j];

    cin>>r2;

    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    cin>>b[i][j];


    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if((a[r1-1][i])==(b[r2-1][j]))
            {
                num[m++]=b[r2-1][j];


            }

        }


    }
    if(m==1)
    cout<<"Case #"<<k+1<<": " <<num[0]<<endl;
    else if(m>1)
    cout<<"Case #"<<k+1<<": Bad magician!"<<endl;
    else
    cout<<"Case #"<<k+1<<": Volunteer cheated!"<<endl;
    }


    return 0;
}
