#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;
#define maxn 10010

int p[maxn],d[maxn],len[maxn];

int i,j,n,m;

int main(){
        int ii,nn;
        scanf("%d",&nn);
        for(ii=1;ii<=nn;ii++){
                printf("Case #%d: ",ii);
                scanf("%d",&n);
                scanf("%d %d",&d[1],&len[1]);
                p[1]=d[1];
                int mx=p[1]+p[1];
                for(i=2;i<=n;i++){
                        p[i]=0;
                        scanf("%d %d",&d[i],&len[i]);
                        for(j=1;j<i;j++){
                                int dis=d[i]-d[j];
                                if(dis<=p[j]){
                                        p[i]=dis;
                                        if(dis>len[i])
                                                p[i]=len[i];
                                        break;
                                }
                        }
                        // printf("%d\n",p[i]);
                        if(d[i]+p[i]>mx)
                                mx=d[i]+p[i];
                }

                scanf("%d",&i);
                // printf("%d %d\n",mx,i);
                if(i<=mx)
                        printf("YES\n");
                else printf("NO\n");
        }
        return 0;
}
