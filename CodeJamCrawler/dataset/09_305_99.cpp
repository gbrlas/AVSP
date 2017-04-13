#include<iostream>
using namespace std;

const int maxn=100+2;
int n,m,test;
int a[maxn][maxn],ans[maxn][maxn],fi[5],fj[5];
bool g[maxn][maxn][5];

void dfs(int i,int j,int flag)
{
     ans[i][j]=flag;
     
     for (int k=1;k<=4;k++)
     if ( (g[i][j][k]) && (ans[i+fi[k]][j+fj[k]]==-1) ) dfs(i+fi[k],j+fj[k],flag);
}

int main()
{
    scanf("%d",&test);
    fi[1]=-1; fj[1]=0;
    fi[2]=0; fj[2]=-1;
    fi[3]=0; fj[3]=1;
    fi[4]=1; fj[4]=0;
    
    for (int t=1;t<=test;t++)
    {
          scanf("%d%d",&n,&m);
          for (int i=1;i<=n;i++)
          for (int j=1;j<=m;j++) scanf("%d",&a[i][j]); 
          
          memset(g,false,sizeof(g));
          for (int i=1;i<=n;i++)
          for (int j=1;j<=m;j++) 
          {
              int min=a[i][j]-1;
              for (int k=1;k<=4;k++) 
              if ( (i+fi[k]>=1) && (i+fi[k]<=n) && (j+fj[k]>=1) && (j+fj[k]<=m) && (a[i+fi[k]][j+fj[k]]<min) ) min=a[i+fi[k]][j+fj[k]];
              for (int k=1;k<=4;k++)
              if ( (i+fi[k]>=1) && (i+fi[k]<=n) && (j+fj[k]>=1) && (j+fj[k]<=m) && (a[i+fi[k]][j+fj[k]]==min) ) 
              {
                 g[i][j][k]=true;
                 g[i+fi[k]][j+fj[k]][4-k+1]=true;
                 break;
              }
          }
          
          int tot=0;
          memset(ans,255,sizeof(ans));
          for (int i=1;i<=n;i++)
          for (int j=1;j<=m;j++) 
          if (ans[i][j]==-1) dfs(i,j,++tot);
          
          printf("Case #%d:\n",t);
          for (int i=1;i<=n;i++)
          for (int j=1;j<=m;j++) 
          {
              printf("%c",ans[i][j]+'a'-1);
              if (j==m) printf("\n");
              else printf(" ");
          }
    }
}
