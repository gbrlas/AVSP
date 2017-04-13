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

const int MaxN = 105;

int a[MaxN], onext[MaxN], bnext[MaxN];
bool blue[MaxN];

int main(){
freopen("A-small-attempt0.in", "r", stdin);
freopen("A-small-attempt0.out", "w", stdout);
int TT; scanf("%d'", &TT);
for (int T = 1; T <= TT; T++){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        char ch; scanf(" %c %d", &ch, &a[i]);
        blue[i] = (ch == 'B');
    }

    memset(bnext, 0, sizeof(bnext));
    memset(onext, 0, sizeof(onext));

    int i = n;
    while (!blue[i] && i) i--;

    for (; i; ){
        int j = i; i--;
        while (!blue[i] && i){
            bnext[i] = a[j];
            i--;
        }
    }

    i = n;
    while (blue[i] && i) i--;

    for (; i; ){
        int j = i; i--;
        while (blue[i] && i){
            onext[i] = a[j];
            i--;
        }
    }

    //for (int i = 1; i <= n; i++) printf("%d %d\n", blue[i], a[i]);
    //for (int i = 1; i <= n; i++) printf("%d ", bnext[i]); printf("\n");
    //for (int i = 1; i <= n; i++) printf("%d ", onext[i]); printf("\n");

    int bpos = 1, opos = 1, sol = 0;
    for (int i = 1; i <= n; i++){
        if (blue[i]){
            int x = abs(a[i] - bpos) + 1;
            bpos = a[i];
            sol += x;
            if (onext[i])
                if (abs(opos - onext[i]) <= x) opos = onext[i];
                else
                    if (opos < onext[i]) opos += x;
                    else opos -= x;
        }
        else {
            int x = abs(a[i] - opos) + 1;
            opos = a[i];
            sol += x;
            if (bnext[i])
                if (abs(bpos - bnext[i]) <= x) bpos = bnext[i];
                else
                    if (bpos < bnext[i]) bpos += x;
                    else bpos -= x;

        }
        //printf("i = %d sol = %d bpos = %d opos = %d\n", i, sol, bpos, opos);
    }
    printf("Case #%d: %d\n", T, sol);
}
fclose(stdin); fclose(stdout);
    return 0;
}
