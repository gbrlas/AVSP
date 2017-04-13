#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define MAXN 2020
using namespace std;
int p,a[MAXN],cost[20][MAXN];
bool flag[20][MAXN];
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int t,ans;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%d",&p);
        for(int i=0;i<(1<<p);i++)
            scanf("%d",a+i);
        /*for(int i=0;i<(1<<p);i++)
            printf("%-4d",a[i]);
        printf("\n");*/
        for(int i=0;i<p;i++)
            for(int j=0;j<(1<<(p-i-1));j++)
                scanf("%d",&cost[i][j]);
        /*printf("cost:\n");
        for(int i=0;i<p;i++){
            for(int j=0;j<(1<<(p-i-1));j++)
                printf("%-4d",cost[i][j]);
            printf("\n");
        }*/
        memset(flag,false,sizeof(flag));
        ans=0;
        for(int i=0;i<(1<<p);i++){
            int index=i/2;
            for(int j=0;j<p;j++){
                if(j>=a[i]&&!flag[j][index]){
                    ans+=cost[j][index];
                    flag[j][index]=true;
                    //printf("i=%d\tcost[%d][%d]=%d\n",i,j,index,cost[j][index]);
                }
                //else
                    //break;
                index/=2;
            }
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    //while(1);
    return 0;
}
                
