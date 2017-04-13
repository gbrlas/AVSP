#include <algorithm>
#include <iostream>
#include <complex>
#include <numeric>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

char s[1024],p[]="welcome to code jam";
int F[512][20];

int f(int i,int j){
    if(s[i]==0)return p[j]==0;
    int&res=F[i][j];
    if(res<0){
        res=f(i+1,j);
        if(s[i]==p[j])res+=f(i+1,j+1);
        res%=10000;
    }
    return res;
}

void Solve(){
    gets(s);
    memset(F,-1,sizeof F);
    printf("%04d\n",f(0,0));
}

int main(){
    #ifdef LocalHost
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
    #endif
    char tmp[32];
    int a=0,b;
    for(b=atoi(gets(tmp));a++<b;Solve())printf("Case #%d: ",a);
    return 0;
}
