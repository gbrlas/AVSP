#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long

double C,F,X;

double f(int x) {
    double t = 0.0, p = 2.0;
    for (int i=0; i<=x-1; i++,p+=F)
        t += C/p;
    t += X/p;
    return t;
}

int main() {
    int nt,lo,hi,mid,nteste=1;
    scanf("%d",&nt);
    while (nt--) {
        scanf("%lf %lf %lf",&C,&F,&X);
        lo = 0; hi = 200002;
        while (lo < hi) {
            mid = (lo+hi)/2;
            if (f(mid) < f(mid+1)) hi = mid;
            else lo = mid+1;
        }
        printf("Case #%d: %.7lf\n",nteste++,f(lo));
    }
    
    return 0;
}
