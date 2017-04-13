#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=107;
const int dx[]={0,1,-1,0};
const int dy[]={1,0,0,-1};
int g[maxn][maxn];
int c[maxn],n,m;

bool vis[maxn][maxn];
int check_r(int k){
    bool ok;
    for(int i=0;i<m;i++)if(g[0][i]<=k){
        ok=false;
        for(int j=0;j<n;j++)if(g[j][i]>k){ok=true;break;}
        if(ok)continue;
        for(int j=0;j<n;j++)if(!vis[j][i]){c[k]--;vis[j][i]=1;}
        if(!c[k])return 1;
    }
    return 0;
}

int check_c(int k){
    bool ok;
    for(int i=0;i<n;i++)if(g[i][0]<=k){
        ok=false;
        for(int j=0;j<m;j++)if(g[i][j]>k){ok=true;break;}
        if(ok)continue;
        for(int j=0;j<m;j++)if(!vis[i][j]){c[k]--;vis[i][j]=1;}
        if(!c[k])return 1;
    }
    return 0;
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
   // freopen("1.txt","r",stdin);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        int maxs=0;
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                scanf("%d",&g[i][j]);
                if(g[i][j]>maxs)maxs=g[i][j];
                c[g[i][j]]++;
            }
        bool ok=true;

        c[maxs]=0;
        for(int i=maxs-1;i>=1;i--){
            if(!c[i])continue;
            memset(vis,0,sizeof(vis));
            int t=check_r(i);
            if(t)continue;
            t=check_c(i);
            if(c[i]){ok=false;break;}
        }
        printf("Case #%d: ",kase);
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}
