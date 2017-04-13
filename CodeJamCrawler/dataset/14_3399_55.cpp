#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T, a, b, row[17][2];

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int k;
        scanf("%d", &a);
        for (int i = 0; i < 16; i++) {
            scanf("%d", &k);
            row[k][0] = i / 4 + 1;
        }
        scanf("%d", &b);
        for (int i = 0; i < 16; i++) {
            scanf("%d", &k);
            row[k][1] = i / 4 + 1;
        }

        int n = 0;
        int choice = 0;
        for (int i = 1; i <= 17; i++) {
            if (row[i][0] == a && row[i][1] == b) {
                n++;
                choice = i;
            }
        }

        printf("Case #%d: ", t);
        if (n == 0) {
            printf("Volunteer cheated!\n");
        } else if (n > 1) {
            printf("Bad magician!\n");
        } else {
            printf("%d\n", choice);
        }
    }

    return 0;
}
