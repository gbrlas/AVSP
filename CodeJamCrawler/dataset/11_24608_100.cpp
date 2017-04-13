#include <stdio.h>

inline int abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    int testnum, n, pos, posO, posB, tO, tB;
    char str[5];

    scanf("%d", &testnum);
    for (int test = 1;test <= testnum;test++) {
        scanf("%d", &n);
        tO = tB = 0;
        posO = posB = 1;
        for (int i = 0;i < n;i++) {
            scanf("%s%d", str, &pos);
            if (str[0] == 'O') {
                tO += abs(pos - posO) + 1;
                if (tO <= tB)
                    tO = tB + 1;
                posO = pos;
            } else {
                tB += abs(pos - posB) + 1;
                if (tB <= tO)
                    tB = tO + 1;
                posB = pos;
            }
        }
        printf("Case #%d: %d\n", test, tO > tB ? tO : tB);
    }
    return 0;
}
