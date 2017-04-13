#include<iostream>
#define oo (int)1e9
#define s(n)scanf("%d",&n)
using namespace std;

int a[111][111];
int t;
int cs;
char ans[111][111];
int r,c;
bool vis[111][111];
char ass;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int sx,sy;
int done;
bool over;

void getmax()
{
     over=1;
     int m = -1;
     for(int i=0;i<r;i++)
      for(int j=0;j<c;j++)
       if(!vis[i][j] and a[i][j] > m )
       {
         sx=i;sy=j;
         m=a[i][j];
         over=0;
       }
}
void go(int x,int y)
{
     int nxtx,nxty,ht=a[x][y];
     bool yes=0;
     for( int i=0;i<4;i++ )
     {
          int nx=x+dx[i];
          int ny=y+dy[i];          
          
          if(nx>=0 and ny>=0 and nx<r and ny<c and a[nx][ny] < ht)
          {
             nxtx=nx;nxty=ny;
             ht=a[nx][ny];
             yes=1;
          }
     }
     
     if( yes )
     {
         vis[x][y]=1;
         done++;
         if(!vis[nxtx][nxty])
         {
            go(nxtx,nxty);
            ans[x][y]=ass;
         }
         ans[x][y]=min(ass,ans[nxtx][nxty]); 
     }
     else
     {       
         if(!vis[x][y])
         {
            vis[x][y]=1;
            ans[x][y] = ass;
            ass++;
            done++;
         }
     }
}
main()
{
      freopen("B-small-attempt2.in","r",stdin);
      freopen("B-small-attempt2.out","w",stdout);      
      s(t);
      
      while(t--)
      {
         ass = 'a';
         done=0;over=0;
         memset(ans,0,sizeof ans);
         memset(vis,0,sizeof vis);                   
         memset(a,0,sizeof a);
                     
         s(r);s(c);
         for(int i=0;i<r;i++ )
          for( int j=0;j<c;j++ )
             s(a[i][j]);
             
          sx=sy=0;
          
          do
          {
             go(sx,sy);
             getmax();
          }while(!over);

         printf("Case #%d:\n",++cs);
         
         for(int i=0;i<r;i++)
         {
                  for(int j=0;j<c;j++)
                  printf("%c ",ans[i][j]);
                  printf("\n");
         }
      }
      //system("pause");

}
