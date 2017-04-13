#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;


static int m1[7];

void init() {
    m1[0] = 1;
    m1[1] = 10;
    m1[2] = 100;
    m1[3] = 1000;
    m1[4] = 10000;
    m1[5] = 100000;
    m1[6] = 1000000;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t = 1, a, b, digits, n, lim, cnt;
    int i, j, k, no2, minNo;
    int noRepetir[6], noRepetirCnt;
    init();

    scanf("%d", &T);
    while (T--) {
        // Entrada
        scanf("%d %d", &a, &b);
        // Prepracion
        n = a; digits = 1;
        while(n > 9) {
            digits++;
            n /= 10;
        }
        cnt = 0;
        lim = b+1;
        // Solucion
        if(digits != 1) {
            minNo = pow(10, digits-1);
            for(n = a; n != lim; n++) {
                noRepetirCnt = 0;
                for(i = digits-1, j = 1; i != 0; i--, j++) {
                    k = n/m1[i];
                    no2 = (n-k*m1[i])*m1[j]+k;
                    if( !(no2 < minNo) && no2 <= b && n < no2 && n != no2 ) {
                        if(noRepetirCnt == 0 || find(noRepetir, noRepetir+noRepetirCnt, no2)==(noRepetir+noRepetirCnt) ) {
                            noRepetir[noRepetirCnt++] = no2;
                            cnt++;
                        }
                    }
                }
            }
        }
        // Salida
        printf("Case #%d: %d\n", t++, cnt);

    }

    fclose(stdout);
    return 0;
}
