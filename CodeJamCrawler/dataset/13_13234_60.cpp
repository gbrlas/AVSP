#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define LL long long
using namespace std;
#define mod 1000000007
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define LL long long
const LL INFL = 1e17;
int n,m,k,T;
int s[110][110];

int is_ok(int i,int j){
    int flag1 = 0,flag2 = 0,flag3 = 0,flag4 = 0;
    for(int k = 0; k < i; k++)
        if(s[k][j]>s[i][j]) flag1 = 1;
    for(int k = i+1; k < n; k++)
        if(s[k][j]>s[i][j]) flag2 = 1;
    for(int k = 0; k < j; k++)
        if(s[i][k]>s[i][j]) flag3 = 1;
    for(int k = j+1; k < m; k++)
        if(s[i][k]>s[i][j]) flag4 = 1;
    if((flag1 || flag2) && (flag3 || flag4)) return 0;
    return 1;

}

int main(){
    //freopen("1.txt","r",stdin);
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d",&s[i][j]);
        int flag = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(!is_ok(i,j)){
                    flag = 1;
                   // printf("%d %d %d",i,j,s[i][j]);
                    goto aaa;
                }
            }
        aaa: ;
        if(!flag){
            printf("Case #%d: YES\n",cas);
        }else printf("Case #%d: NO\n",cas);
    }
    return 0;
}