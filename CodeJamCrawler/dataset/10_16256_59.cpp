#include <iostream>

using namespace std;

char grid[55][55];
char temp[55][55];

int n,K;
void rotate()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            temp[i][j]=grid[n-j+1][i];
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            grid[i][j]=temp[i][j];
        }
}
void gravity()
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        k=n;
        for(j=n;j>=1;j--)
        {
            if(grid[j][i]!='.') grid[k--][i]=grid[j][i];
        }
        for(;k>=1;k--) grid[k][i]='.';
    }
}
bool count(char c)
{
    int i,j,k;
    for(i=1;i<=n;i++)
       for(j=1;j<=n-K+1;j++)
       {
            for(k=0;k<K;k++)
               if(grid[i][j+k]!=c) break;
            if(k==K) return true;
       }
    for(i=1;i<=n;i++)
       for(j=1;j<=n-K+1;j++)
       {
            for(k=0;k<K;k++)
               if(grid[j+k][i]!=c) break;
            if(k==K) return true;
       }
    for(i=1;i<=n-K+1;i++)
       for(j=K;j<=n;j++)
       {
            for(k=0;k<K;k++)
               if(grid[i+k][j-k]!=c) break;
             if(k==K) return true;
       }
    for(i=1;i<=n-K+1;i++)
       for(j=1;j<=n-K+1;j++)
       {
            for(k=0;k<K;k++)
               if(grid[i+k][j+k]!=c) break;
            if(k==K) return true;
       }
    return 0;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,t;
    int i,j;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n>>K;
        for(i=1;i<=n;i++) cin>>grid[i]+1;
//        for(i=1;i<=n;i++) cout<<grid[i]+1<<endl;
//        cout<<endl;
        rotate();
//        for(i=1;i<=n;i++) cout<<grid[i]+1<<endl;
//        cout<<endl;
        gravity();
//        for(i=1;i<=n;i++) cout<<grid[i]+1<<endl;
//        cout<<endl;
        bool b,r;
        b=count('B');
        r=count('R');
        if(b)
        {
            if(r) cout<<"Case #"<<t<<": "<<"Both"<<endl;
            else cout<<"Case #"<<t<<": "<<"Blue"<<endl;
        }
        else
        {
            if(r) cout<<"Case #"<<t<<": "<<"Red"<<endl;
            else cout<<"Case #"<<t<<": "<<"Neither"<<endl;
        }
    }
    return 0;
}
