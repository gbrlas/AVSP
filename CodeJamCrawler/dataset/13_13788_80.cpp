enum {NO,YES};
#include <iostream>
#include <vector>
using namespace std;
int min_(int a[100][100],int n,int m)
{
    int max1=0,max2=0;
    for(int i=0;i<100;i++)
    {
        if(max1<a[n][i])max1=a[n][i];
    }
    for(int j=0;j<100;j++)
    {
        if(max2<a[j][m])max2=a[j][m];
    }
    if(max1<max2)return max1;
    else
        return max2;
}
int main(int argc, const char * argv[])
{
   freopen("/Users/igorm/Documents/1.txt","w",stdout
            );
    freopen("/Users/igorm/Documents/A.txt","r",stdin);
    int a[100][100];
    int t;
    
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,m;
        bool ans=true;
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++)a[i][j]=-100;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(a[i][j]<min_(a,i,j))
                {
                    ans=false;
                }
            }
        if(ans)cout<<"Case #"<<k+1<<": YES"<<endl;
                   else
                   cout<<"Case #"<<k+1<<": NO"<<endl;
    }
    return 0;
}

