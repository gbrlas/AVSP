#include<cstdio>
#include<cstring>
#include <cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

const int maxn = 100 + 5;

int M[maxn][maxn];
int Maxx[maxn],Maxy[maxn];

int main(){
    freopen("outans","w",stdout);
    int n,m,t,kase = 0,Maxn;
    scanf("%d",&t);
    while(t--){
        kase++;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++){
            Maxn = 0;
            for(int j = 0;j < m;j++){
                scanf("%d",&M[i][j]);
                Maxn = max(Maxn,M[i][j]);
            }
            Maxx[i] = Maxn;
        }
        for(int i = 0;i < m;i++){
            Maxn = 0;
            for(int j = 0;j < n;j++){
                Maxn = max(Maxn,M[j][i]);
            }
            Maxy[i] = Maxn;
        }
        //for(int i = 0;i < n;i++) printf("%d ",Maxx[i]);printf("\n");
        //for(int i = 0;i < m;i++) printf("%d ",Maxy[i]);printf("\n");
        int ans = 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                if(M[i][j] < Maxx[i] && M[i][j] < Maxy[j]){
                    ans = 0;break;
                }
        }
        if(ans == 1) printf("Case #%d: YES\n",kase);
        else printf("Case #%d: NO\n",kase);
    }
    return 0;
}
