#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#define MAXN 600
#define eps 1e-9
using namespace std;
char g[MAXN][MAXN];
int r,c,d;
bool judge(int num)
{
    int x,y;
    double xx,yy,cx,cy;
    int dx[4],dy[4];
    for(int i=0;i+num<=r;i++){
        for(int j=0;j+num<=c;j++){
            xx=yy=0;
            cx=(i+i+num)/2.0;
            cy=(j+j+num)/2.0;
            for(int k=0;k<num;k++){
                for(int l=0;l<num;l++){
                    xx+=(g[i+k][j+l]-'0'+d)*(i+k+0.5-cx);
                    yy+=(g[i+k][j+l]-'0'+d)*(j+l+0.5-cy);
                }
            }
            dx[0]=i;
            dy[0]=j;
            
            dx[1]=i;
            dy[1]=j+num-1;
            
            dx[2]=i+num-1;
            dy[2]=j;
            
            dx[3]=i+num-1;
            dy[3]=j+num-1;
            
            for(int k=0;k<4;k++){
                x=dx[k];
                y=dy[k];
                xx-=(g[x][y]-'0'+d)*(x+0.5-cx);
                yy-=(g[x][y]-'0'+d)*(y+0.5-cy);
            }
            //printf("i=%d\tj=%d\txx=%f\ty=%f\n",i,j,xx,yy);
            //printf("cx=%f\tcy=%f\n",cx,cy);
            if(xx<eps&&xx>-eps&&yy<eps&&yy>-eps){
                //printf("i=%d\tj=%d\txx=%f\ty=%f\n",i,j,xx,yy);
                //printf("cx=%f\tcy=%f\n",cx,cy);
                return true;
            }
            
        }
    }
    return false;
}
            
int main()
{
    freopen("B-small-attempt0(1).in","r",stdin);
    freopen("B-small-attempt0(1).out","w",stdout);
    int t,ans,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&r,&c,&d);
        for(int i=0;i<r;i++)
            scanf("%s",g[i]);
        ans=-1;
        for(int i=3;i<=min(r,c);i++)
            if(judge(i))
                ans=i;
        printf("Case #%d: ",++cas);
        if(ans==-1)
            puts("IMPOSSIBLE");
        else
            printf("%d\n",ans);
    }
    //while(1);
    return 0;
}
    
    
