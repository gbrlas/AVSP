#include <stdio.h>
#include <algorithm>

using namespace std;


struct GOOGLER {
    int points;
    bool woS, wS;
};


inline int checkN(int n) { if(n < 0) return 0; else return n; }

void verify(int totalPoints, int minPoints, GOOGLER *g) {
    int p, remaining, val[5], i, j, diff, m[3];
    g->woS = false; g->wS = false;
    //
    for(p = minPoints; p != 11 && (g->woS == false || g->wS == false); p++) {
        remaining = totalPoints-p;
        val[0] = checkN(p-2); val[1] = checkN(p-1); val[2] = p; val[3] = p+1; val[4]=p+2;
        for(i = 0; i != 5; i++) {
            for(j = 0; j != 5; j++) {
                if( (val[i]+val[j])==remaining) {
                    m[0] = val[i]; m[1] = val[j]; m[2] = p;
                    sort(m, m+3);
                    diff = (m[2]-m[0]);
                    if(diff < 3) {
                        if(diff == 2) {
                            g->wS = true;
                        } else {
                            g->woS = true;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t=1, n, s, p;
    GOOGLER *gg;
    int cnt, i, j;

    scanf("%d", &T);
    while( T-- ) {
        // Entrada
        scanf("%d %d %d", &n, &s, &p);
        gg = new GOOGLER[3];
        for(i = 0; i != n; i++) scanf("%d", &(gg[i].points) );
        // Solucion
        for(i = 0; i != n; i++) verify(gg[i].points, p, &gg[i]);
        cnt = 0;
        if( s == 0 ) {
            for(i = 0; i != n; i++) cnt += gg[i].woS;
        } else if( s == 3 ) {
            for(i = 0; i != n; i++) cnt += gg[i].wS;
        }
        // Para los casos de s=1 y s=2
        if(s == 1) {
            if(n == 1) {
                cnt = gg[0].wS;
            } else if( n == 2) {
                cnt = max( gg[0].wS+gg[1].woS, gg[1].wS+gg[0].woS ) ;
            } else if (n == 3) {
                cnt = max(
                          max( gg[0].wS+gg[1].woS+gg[2].woS, gg[0].woS+gg[1].wS+gg[2].woS),
                          gg[0].woS+gg[1].woS+gg[2].wS
                          );
            }
        }
        if(s == 2) {
            if( n == 2) {
                cnt = gg[0].wS + gg[1].wS;
            } else if (n == 3) {
                cnt = max(
                          max( gg[0].wS  +gg[1].wS +gg[2].woS, gg[0].woS +gg[1].wS  +gg[2].wS),
                           gg[0].wS +gg[1].woS +gg[2].wS
                           );
            }
        }
        // Salida
        printf("Case #%d: %d\n", t++, cnt);
        //for(i = 0; i != n; i++) printf("%d, wS=%d, woS=%d\n", gg[i].points, gg[i].wS, gg[i].woS );
    }

    fclose(stdout);
    return 0;
}
