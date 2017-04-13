#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define REP(op,s,t) for (op=(s);op<=(t);op++) 
#define DEP(op,s,t) for (op=(s);op>=(t);op--) 
#define MXN 10000
#define FILENAME "a"
typedef long long LL;
using namespace std;
long TESTPOINT,n,k,i,K;

int main(){
    freopen(FILENAME".in","r",stdin);
    freopen(FILENAME".out","w",stdout);
    scanf("%d",&TESTPOINT);
    for (long TP=1;TP<=TESTPOINT;TP++){
        scanf("%d%d",&n,&k);
        K=(1<<n)-1;
        if ((k&K)!=K) printf("Case #%d: OFF\n",TP);else printf("Case #%d: ON\n",TP);
    }
    return 0;
}
