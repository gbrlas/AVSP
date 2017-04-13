#include<iostream>
#include<cmath>
using namespace std;
bool lawnsmall(int low,int high);
bool compare();
int m,n;
int a[100][100],res[100][100];

int main()
{
    int TT;
 freopen("B-large(1).in","r",stdin);
    freopen ("outputlawn.txt","w",stdout);
    cin>>TT;
    int low,high,x=0;
    while(TT--)
    {
        x++;
        cin>>m>>n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
        {
            cin>>a[i][j];

        }
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
        {
            res[i][j] = 100;

        }
        
        for(int i=100;i>=2;i=i-1)
        {
            high=i;
            low = i-1;
            lawnsmall(low,high);
         }
        if( compare()==1)
               cout<<"Case #"<<x<<": YES"<<endl;
           else 
               cout<<"Case #"<<x<<": NO"<<endl;
    }
    return 0;
}

bool lawnsmall(int low,int high){
    bool flag;
    
        
        for(int i=0;i<m;i++)
           {
               flag = 1;

                for(int j=0;j<n;j++)
                {
                    if(a[i][j]<high)
                     {

                     }  // flag = 1;
                    else{
                       flag=0;
                       break;
                    }


                }
                if (flag == 1)
                {
                    for(int k=0;k<n;k++)
                        res[i][k]=low;
                }
           }

           for(int j=0;j<n;j++)
           {
               flag = 1;

                for(int i=0;i<m;i++)
                {
                    if(a[i][j]<high)
                    {

                    }    //flag = 1;
                    else{
                        flag =0;
                        break;
                    }


                }
                if (flag == 1)
                {
                    for(int k=0;k<m;k++)
                        res[k][j]=low;
                }
           }
    return 0;
}

bool compare()
{
    bool flag=1;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=res[i][j]){
                flag=0;
                break;
            }
        }
    return flag;
}