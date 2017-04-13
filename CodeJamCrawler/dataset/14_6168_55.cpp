#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    freopen("A-small-attempt3.in", "r", stdin);
    freopen("A-small-attempt3.out", "w", stdout);
    int N,row1,row2,temp;
    int count=1;
    bool flag=true;
    int arr1[4][4],arr2[4][4],arr[17];
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>row1;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cin>>arr1[i][j];
            }
        }


        cin>>row2;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cin>>arr2[i][j];
            }
        }
        for(int i=0; i<17; i++)
        {
            arr[i]=0;
        }
        int i=row1-1;
        for(int j=0; j<4; j++)
        {
            arr[arr1[i][j]]=1;

        }

        i=row2-1;
        int c=0;
        for(int j=0; j<4; j++)
        {
            if(arr[arr2[i][j]]==1)
            {
                temp=arr2[i][j];

                c++;
            }

        }

        if(c==1)
            cout<<"Case #"<<count++<<": "<<temp<<"\n";
        else if(c>1)
            cout<<"Case #"<<count++<<": "<<"Bad magician!\n";
        else if(c==0)
            cout<<"Case #"<<count++<<": "<<"Volunteer cheated!\n";

    }
}
