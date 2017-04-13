#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define IM 110

int N,M;
int xMax[IM],yMax[IM];
int g[IM][IM];

void Deal()
{
    int ans;
    for(int i = 0;i < N;i++){
        ans = 0;
        for(int j = 0;j < M;j++)
            if(g[i][j] > ans)
                ans = g[i][j];
        xMax[i] = ans;
    }
    for(int i = 0;i < M;i++){
        ans = 0;
        for(int j = 0;j < N;j++)
            if(g[j][i] > ans)
                ans = g[j][i];
        yMax[i] = ans;
    }
}

bool Judge()
{
    for(int i = 0;i < N;i++)
        for(int j = 0;j < M;j++){
            if(g[i][j] != xMax[i] && g[i][j] != yMax[j])
                return false;
        }
    return true;
}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas = 1;cas <=T;++cas){
        scanf("%d%d",&N,&M);
        for(int i = 0;i < N;i++)
            for(int j = 0;j < M;j++)
                scanf("%d",&g[i][j]);
        Deal();
        bool flage = Judge();

        printf("Case #%d: ",cas);

        if(flage == true){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
