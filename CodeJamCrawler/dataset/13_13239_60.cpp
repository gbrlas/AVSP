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
char s[110];

int is_ok(int i,int j){

}

int main(){
    //freopen("1.txt","r",stdin);
    freopen("C-small-attempt0.in","r",stdin);
    freopen(" C-small-attempt0.out","w",stdout);

    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++){
        int a,b;
        scanf("%d%d",&a,&b);
        int res = 0;
        for(int j = 1; j <= 40; j++){
            if(j*j >= a && j*j <= b){
                sprintf(s,"%d",j*j);
                int len = strlen(s);
                int flag1 = 0,flag2 = 0;
                for(int k = 0; k < len; k++)
                    if(s[k]!=s[len-k-1]) flag1 = 1;
                sprintf(s,"%d",j);
                len = strlen(s);
                flag2 = 0;
                for(int k = 0; k < len; k++)
                    if(s[k]!=s[len-k-1]) flag2 = 1;
                if(!flag1&&!flag2) {
                    res++;
                    // printf("%d\n",j*j);
                }
            }
        }
        printf("Case #%d: %d\n",cas,res);
    }
    return 0;
}