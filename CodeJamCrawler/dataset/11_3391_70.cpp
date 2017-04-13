#include <cstdio>
#include <cstdlib>

using namespace std;

typedef struct _Node {
    char c[3];
    int x;
} Node;

Node S[200];

int main(void) {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    int n;
    scanf ("%d", &T);
    for (int x = 1; x <= T; ++x) {
        scanf ("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf ("%s %d", S[i].c, &S[i].x);
        }
        int o_pos = 1;
        int b_pos = 1;
        int second = 0;
        int o_r = 0;
        int b_r = 0;
        for (int i = 0; i < n; ++i) {
            if (S[i].c[0] == 'O') {
                int add = 0;
                int dis = abs(o_pos - S[i].x);
                if (o_r >= dis) {
                    add = 1;
                } else {
                    add = dis-o_r + 1;
                }
                second += add;
                b_r += add;
                o_pos = S[i].x;
                o_r = 0;
            } else {
                int add = 0;
                int dis = abs(b_pos - S[i].x);
                if (b_r >= dis) {
                    add = 1;
                } else {
                    add = dis-b_r + 1;
                }
                second += add;
                b_pos = S[i].x;
                o_r += add;
                b_r = 0;
            }
        }
        printf ("Case #%d: %d\n", x, second);
    }


    return 0;
}
