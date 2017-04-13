#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

#define PI 3.14159265358979323
#define INF 2123456789
#define NUL 0.0000001

#define PB push_back
#define SZ size()
#define CS c_str()
#define LEN length()
#define CLR clear()
#define EMP empty()
#define INS insert

const int MaxX = 1000005;

int a[MaxX], f[MaxX];

int main(){
freopen("A-large.in", "r", stdin);
freopen("A-large.out", "w", stdout);

int T; scanf("%d", &T);
for (int tt = 1; tt <= T; tt++){
    int x, s, r, X, n; scanf("%d%d%d%d%d", &x, &s, &r, &X, &n);

    double t = X;

    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++){
        int b, e, w; scanf("%d%d%d", &b, &e, &w);
        a[b] += w; a[e] -= w;
    }

    int tSpeed = s;
    for (int i = 0; i < x; i++){
        tSpeed += a[i];
        f[i] = tSpeed;
    }

    sort(f, f+x);
    //for (int i = 0; i < x; i++) printf("%d ", f[i]); printf("\n");

    double sol = 0.0;
    for (int i = 0; i < x; i++){
        if ( 1.0 / double(f[i] + r - s) < t + NUL ){
            sol += 1.0 / double(f[i] + r - s);
            t -= 1.0 / double(f[i] + r - s);
        }
        else if (t < NUL){
            sol += 1.0 / double(f[i]);
        }
        else {
            sol += t + (1.0 - double(f[i] + r - s) * t) / double(f[i]);
            t = 0.0;
        }
        //printf("t =
    }
    printf("Case #%d: %.10lf\n", tt, sol);
}

fclose(stdin); fclose(stdout);
    return 0;
}
