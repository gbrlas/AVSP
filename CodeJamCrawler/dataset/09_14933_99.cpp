#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
template <class T> void out(T x, int n){  for(int i = 1; i <= n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void out(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
#define OUT(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  LL long long
#define  eps 1e-8
#define  pi  acos(-1)
const int maxn = 105,INF = 0x7fffffff;

int n,m,col;
int h[maxn][maxn],grid[maxn][maxn];
int X[]={-1,0,0,1};
int Y[]={0,-1,1,0};
bool is_ok(int x,int y)
{
   if(x>=1&&x<=n&&y>=1&&y<=m)  return 1;
   else return 0;
}
void dfs(int i,int j)
{
//    cout<<i<<" "<<j<<endl;
    grid[i][j]=col;
    int k,p,x,y,t_x,t_y,min,index;
    for(k=0;k<4;k++)
    {
        x=i+X[k],y=j+Y[k];
        if(is_ok(x,y)&&grid[x][y]==-1)
        {
            min=h[x][y];
            for(p=0;p<4;p++)
            {
               t_x=x+X[p],t_y=y+Y[p];
               if(is_ok(t_x,t_y))
               {
                   if(min>h[t_x][t_y])  min=h[t_x][t_y],index=p;
               }
            }
            if(min!=h[x][y])
            {
                t_x=x+X[index],t_y=y+Y[index];
                if(t_x==i&&t_y==j)  dfs(x,y);
            }
        }
    }
}
char change[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,t,T,x,y,sum,index;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
               scanf("%d",h[i]+j);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                grid[i][j]=-1;
        bool ok=0;col=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                 for(k=0;k<4;k++)
                 {
                     x=i+X[k],y=j+Y[k];
                     if(is_ok(x,y))
                     {
                        if(grid[i][j]!=-1||h[x][y]<h[i][j]) break;
                     }
                 }
                 if(k>=4)  dfs(i,j),col++;
            }
//        out(grid,n,m);
        for(i=0;i<col;i++)
            change[i]='z'+1;
        int cp=0;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                      if(change[grid[i][j]]=='z'+1)
                      {
                          change[grid[i][j]]=cp+'a';
                          cp++;
                      }
            }
        printf("Case #%d:\n",t);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                putchar(change[grid[i][j]]);
                if(j!=m) putchar(' ');
            }
            puts("");
        }

    }
    return 0;
}
