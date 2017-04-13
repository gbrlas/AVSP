#include <iostream>
#include <stdio.h>
#define MAX 10
using namespace std;
int main()
{
    int m,n;
    int TT;
    freopen ("B-small-attempt0.in","r",stdin);
    freopen ("outputlawn.txt","w",stdout);
    cin>>TT;
    int x = 0;
    while(TT--)
    {
        x++;
        cin>>m;
        cin>>n;
        int a[MAX][MAX],res[MAX][MAX],flag;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                    cin>>a[i][j];
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                    res[i][j] = 2;
        
        for(int i=0;i<m;i++)
           {
               flag = 1;

                for(int j=0;j<n;j++)
                {
                    if(a[i][j]==1)
                     {
                     }  // flag = 1;
                    else
                       flag=0;
                }
                if (flag == 1)
                {
                    for(int k=0;k<n;k++)
                        res[i][k]=1;                }
           }

           for(int j=0;j<n;j++)
           {
               flag = 1;
                for(int i=0;i<m;i++)
                {
                    if(a[i][j]==1)

                    {

                    }    //flag = 1;
                    else
                        flag =0;


                }
                if (flag == 1)
                {
                    for(int k=0;k<m;k++)
                        res[k][j]=1;
                }
           }

            flag =1;
           for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
           {
               if(a[i][j]!=res[i][j])
                flag = 0;


           }

           if(flag==1)
            cout<<"Case #"<<x<<": YES"<<endl;
           else
            cout<<"Case #"<<x<<": NO"<<endl;




    }
    fclose(stdout);
    return 0;
}