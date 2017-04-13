#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
int mat[6][6];
bool vis[20];
int main()
{
    //freopen("A-small-attempt2.in","r",stdin);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,tcase=0;
    scanf("%d",&t);
    while(t--)
    {
        int row;
        scanf("%d",&row);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=4;++i)
            for(int j=1;j<=4;++j)
                scanf("%d",&mat[i][j]);
        for(int i=1;i<=4;++i)
            vis[mat[row][i]]=true;
        int cnt=0,ans;
        scanf("%d",&row);
        for(int i=1;i<=4;++i)
            for(int j=1;j<=4;++j)
                scanf("%d",&mat[i][j]);
        for(int i=1;i<=4;++i)
            if(vis[mat[row][i]]) {cnt++;ans=mat[row][i];}
        printf("Case #%d: ",++tcase);
        if(cnt==1) printf("%d\n",ans);
        else if(cnt>1) printf("Bad magician!\n");
        else printf("Volunteer cheated!\n");
    }
    return 0;
}
