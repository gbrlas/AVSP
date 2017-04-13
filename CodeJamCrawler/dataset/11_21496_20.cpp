#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

#define N 105
#define inf 0x3f3f3f3f
#define eps 1e-8
#define LL long long

int main(){
    freopen("a.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    double wp[N],owp[N],oowp[N];
    int T,i,j,k,n,cnt,wcnt,fcnt,cas = 0,twp,towp,ccnt,l;
    int g[N][N];
    char s[105];
    scanf("%d",&T);
    s[0] = ' ';
    while (T--){
        ++cas;
        memset(g,-1,sizeof(g));
        memset(wp,0,sizeof(wp));
        memset(owp,0,sizeof(owp));
        memset(oowp,0,sizeof(oowp));
        scanf("%d",&n);
        getchar();
        for (i=1;i<=n;++i){
            scanf("%s",&s[1]);
            cnt = wcnt = 0;
            for (j=1;j<=n;++j){
                if (s[j] == '1'){
                    g[i][j] = 1;
                    cnt++;
                    wcnt++;
                }
                if (s[j] == '0'){
                    cnt ++;
                    g[i][j] = 0;
                }
            }
            wp[i] = double(wcnt) / double(cnt);
        }
        for (i = 1; i <= n; ++i){
            fcnt = 0;
            for (j = 1; j <= n; ++j){
                if (g[i][j] != -1){
                    fcnt++;
                    wcnt = cnt = 0;
                    for (k = 1; k <= n; ++k){
                        if (k != i){
                            if (g[j][k] == 1){
                                wcnt++;
                                cnt++;
                            }
                            if (g[j][k] == 0){
                                cnt++;
                            }
                        }
                    }
                    owp[i] += double(wcnt) / double(cnt);
                }
            }
            owp[i] /= double(fcnt);
        }
        for (i = 1; i <= n; ++i){
            fcnt = 0;
            for (j = 1; j <= n; ++j){
                if (g[i][j] != -1){
                    fcnt ++;
                    oowp[i] += owp[j];
                }
            }
            oowp[i] /= double(fcnt);
        }
        printf("Case #%d: \n",cas);
        for (i = 1; i <= n; ++i){
            printf("%.8lf\n",0.25*wp[i] + 0.5*owp[i] + 0.25*oowp[i]);
        }
    }
    return 0;
}
