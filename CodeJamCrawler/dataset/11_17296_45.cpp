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

const int MaxN = 1005;

int a[MaxN];

int main(){
freopen("C-small-attempt0.in", "r", stdin);
freopen("C-small-attempt0.out", "w", stdout);
int TT; scanf("%d'", &TT);
for (int T = 1; T <= TT; T++){
    int n, sum = 0, m = INF; scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
        m = min(m, a[i]);
    }

    int x = a[1];
    for (int i = 2; i <= n; i++) x = x ^ a[i];

    if (x){
        printf("Case #%d: NO\n", T);
        continue;
    }

    printf("Case #%d: %d\n", T, sum - m);
}
fclose(stdin); fclose(stdout);
    return 0;
}
