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
#define NUL 0.0000000001

#define PB push_back
#define SZ size()
#define CS c_str()
#define LEN length()
#define CLR clear()
#define EMP empty()
#define INS insert

int n, d, v[205], p[205];

double max(double a, double b){
    if (a + NUL < b) return b;
    return a;
}

bool Good(double t){
    double gr = -20000000000000.0;
    for (int i = 1; i <= n; i++){
        gr = max(gr, double(p[i]) - t);



        double x = double(v[i]); x -= 1.0; x *= double(d);
        x += gr;

        if (x < double(p[i]) + t + NUL) gr = x + double(d);
        else return false;
    }
    return true;
}

int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

int T; scanf("%d", &T);
for (int TT = 1; TT <= T; TT++){
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i], &v[i]);

    //double l = 0.0, r = 10000000000000.0, t;
    double l = 0.0, r = 10000000000000.0, t;

    while (l + NUL < r){
        t = (l + r) / 2.0;

        //printf("%.10lf\n", t);
        if (Good(t)) r = t;
        else l = t + NUL;
    }

    if (!Good(t)) t += NUL;
    printf("Case #%d: %.10lf\n", TT, t);
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
