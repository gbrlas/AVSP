#include <cstdio>

int main() {
    int T, t, n, s, p, score;

    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        int num = 0;
        scanf("%d %d %d", &n, &s, &p);
        for (int i = 0; i < n; i++) {
            scanf("%d", &score);
            if (score % 3 == 0) {
                if (score / 3 >= p) num++;
                else if (s && score && score / 3 + 1 == p) {
                    num++;
                    s--;
                }
            } else if (score % 3 == 1) {
                if (score / 3 + 1 >= p) num++;
            } else if (score % 3 == 2) {
                if (score / 3 + 1 >= p) num++;
                else if (s && score / 3 + 2 == p) {
                    num++;
                    s--;
                }
            }
        }
        printf("Case #%d: %d\n", t, num);
    }
    return 0;
}


