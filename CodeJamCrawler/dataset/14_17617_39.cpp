#include <cstdio>

int a[4][4], b[4][4];

int main() {
    int tasks; scanf("%d", &tasks);
    for (int cas = 1; cas <= tasks; ++cas) {
        printf("Case #%d: ", cas);
        int r1, r2; scanf("%d", &r1);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                scanf("%d", &a[i][j]);
        scanf("%d", &r2);
        --r1; --r2;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                scanf("%d", &b[i][j]);
        int cnt = 0, who = -1;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                if (a[r1][i] == b[r2][j]) {
                    ++cnt ; who = a[r1][i]; break; 
                }
        }
        if (cnt == 1) {
            printf("%d\n", who);
        } else
        if (cnt == 0) 
            puts("Volunteer cheated!");
        else puts("Bad magician!");
    }
    return 0;
}
