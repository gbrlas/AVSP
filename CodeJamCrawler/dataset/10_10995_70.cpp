#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Node {
    int loc,v;
};

Node node[60];
bool able[60];
int n,k,b,t,res,use;
int kase;

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    scanf("%d",&kase);
    for (int i=1;i<=kase;i++) {
        scanf("%d%d%d%d",&n,&k,&b,&t);
        res=0;use=0;
        memset(able,false,sizeof(able));
        for (int j=0;j<n;j++) scanf("%d",&node[n-j-1].loc);
        for (int j=0;j<n;j++) scanf("%d",&node[n-j-1].v);
        for (int j=0;j<n;j++) {
            if (use==k) break;
            //printf("%d %d %d %d\n",node[j].loc,node[j].v,(b-node[j].loc)/node[j].v,t);
            if ((b-node[j].loc+node[j].v-1)/node[j].v<=t) {
                //printf("=====%d OK\n",j);
                able[j]=true;
                use++;
                for (int k=j-1;k>=0;k--) if (!able[k]) res++;
            }
            else {
                able[j]=false;
                //printf("=====%d not OK\n",j);
            }
        }
        printf("Case #%d: ",i);
        if (use<k) printf("IMPOSSIBLE\n");
        else printf("%d\n",res);
    }
    return 0;
}
