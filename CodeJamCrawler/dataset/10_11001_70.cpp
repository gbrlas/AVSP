#include <stdio.h>
#include <string.h>

bool used[30];
int num[30];

int kase,n,res;

void check()
{
    memset(num,0,sizeof(num));
    int curr=1;
    for (int i=2;i<=n;i++) {
        if (used[i]) num[i]=curr++;
    }
    //printf("%d\n",curr);
    int k=num[n];
    while (k!=1) {
        if (!used[k]) return;
        k=num[k];
    }
    res++;
    res%=100003;
}

void dfs(int depth) {
    if (depth==n) {
        //printf("=============%d\n",depth);
        check();
        return;
    }
    used[depth]=false;
    dfs(depth+1);
    used[depth]=true;
    dfs(depth+1);
}

int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    scanf("%d",&kase);
    for (int i=1;i<=kase;i++) {
        scanf("%d",&n);
        res=0;
        memset(used,false,sizeof(used));
        used[n]=true;
        dfs(2);
        printf("Case #%d: %d\n",i,res);
    }
    return 0;
}
