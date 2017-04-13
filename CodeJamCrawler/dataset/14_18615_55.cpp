#include <cstdio>

using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    int A[4][4], B[4][4], t, a, b, C[4], c, T, i, j;

    scanf("%d", &T);

    for(t = 1;t <= T;t++) {
        scanf("%d", &a);
        for(i = 0;i < 4;i++) {
            for(j = 0;j < 4;j++) {
                scanf("%d", &A[i][j]);
            }
        }

        scanf("%d", &b);
        for(i = 0;i < 4;i++) {
            for(j = 0;j < 4;j++) {
                scanf("%d", &B[i][j]);
            }
        }
        a--;
        b--;
        c = 0;
        for(i = 0;i < 4;i++) {
            for(j = 0;j < 4;j++) {
                if(A[a][i] == B[b][j]) {
                    C[c++] = A[a][i];
                }
            }
        }

        printf("Case #%d: ", t);

        if(c == 1) {
            printf("%d\n", C[0]);
        } else if(c == 0) {
            printf("Volunteer cheated!\n");
        } else {
            printf("Bad magician!\n");
        }
    }


    return 0;
}
