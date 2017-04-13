#include<iostream>
//#inlcude<stdio.h>

using namespace std;

int main()
{
    int T,k=0;
    cin>>T;
    for(k=1;k<=T;k++)
    {
        int i=0,j=0,a=0,b=0,A[4][4],B[4][4],count=0,temp=0;
        cin>>a;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                cin>>A[i][j];
            }
        }
        cin>>b;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                cin>>B[i][j];
            }
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(A[a-1][i]==B[b-1][j])
                {
                    temp=A[a-1][i];
                    count++;
                }
            }
        }
        if(count==0)
        {
           cout<<"Case #"<<k<<": Volunteer cheated!"<<endl;
        }
        else if(count==1)
        {
            cout<<"Case #"<<k<<": "<<temp<<endl;
        }
        else
        {
            cout<<"Case #"<<k<<": Bad magician!"<<endl;
        }
    }

    return 0;
}

