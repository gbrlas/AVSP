#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <numeric>

#define pii pair<int,int>
#define FOR(i,n) for (int i = 1, _n = n; i <= _n; i++)
#define FOD(i,n) for (int i = n; i >= 0; i--)
#define MAXINT 1000000000

using namespace std;

int tc, L, P, C;

int val(int a){
    int ans = 1;
    for (int i = 0; i < a; i++) ans *= C;
    return ans;
}

int f(int lower, int upper){
    //printf("lower %d upper %d\n",lower,upper);
    if (C*lower >= upper) return 0;
    double tmp = upper;
    tmp /= lower;
    tmp = ceil(log(tmp)/log(C)/2.0);
    int c = val((int)tmp);
    //test at lower * C
    int a = max(f(lower*c, upper), f(lower, lower*c))+1;
    //test at upper/C
    int k = upper/c+((upper % c != 0)? 1 : 0);
    int b = max(f(lower, k),f(k,upper))+1;
    //printf("%d %d a %d b %d test %d\n",lower, upper, a,b,c);
    return min(a,b);
}

int main(){
    //freopen("input.txt","r",stdin);
    freopen("B-small-attempt2.in","r",stdin);
    scanf("%d",&tc);
    for (int TC = 1; TC <= tc; TC++){
        scanf("%d %d %d",&L,&P,&C);
        printf("Case #%d: %d\n",TC,f(L,P));
    }
    return 0;
}
