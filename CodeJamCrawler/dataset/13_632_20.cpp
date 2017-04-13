#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

char ga[4][4];
int col[4][2], row[4][2], d1[2], d2[2];

int main() {
    freopen("A-small-attempt0.in","r",stdin);
     freopen("out.txt","w+",stdout);
    int c1, c2 = 0;
    scanf("%d", &c1);
    while (c1--) {
        memset(d2, 0, sizeof (d2));
        memset(d1, 0, sizeof (d1));
        memset(col, 0, sizeof (col));
        memset(row, 0, sizeof (row));
        int o = 0, x = 0, end = 1;
        printf("Case #%d: ", ++c2);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                scanf(" %c", ga[i] + j);
                if (ga[i][j] == '.')
                    end = 0;
                if (ga[i][j] == 'O') {
                    col[j][1]++;
                    row[i][1]++;
                    if (i == j) d1[1]++;
                    if (i + j == 3) d2[1]++;
                }
                if (ga[i][j] == 'X') {
                    col[j][0]++;
                    row[i][0]++;
                    if (i == j) d1[0]++;
                    if (i + j == 3) d2[0]++;
                }
                if (ga[i][j] == 'T') {
                    for (int k = 0; k < 2; k++) {
                        col[j][k]++;
                        row[i][k]++;
                        if (i == j) d1[k]++;
                        if (i + j == 3) d2[k]++;
                    }
                }

            }
        for (int i = 0; i < 4; i++) {
            o += (col[i][1] == 4)+(row[i][1] == 4);
            x += (col[i][0] == 4)+(row[i][0] == 4);
        }
        o += (d1[1] == 4)+(d2[1] == 4);
        x += (d1[0] == 4)+(d2[0] == 4);
        if (o) {
            printf("O won\n");
        } else if (x) {
            printf("X won\n");
        } else if (end) {
            printf("Draw\n");
        } else {
            printf("Game has not completed\n");
        }
    }

    return 0;
}
