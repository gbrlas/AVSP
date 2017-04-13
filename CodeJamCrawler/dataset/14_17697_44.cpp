#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main() {
    int N; scanf("%d", &N);
    for (int tc = 1; tc <= N; ++tc) {
       int f[5][5], g[5][5], row1[17], row2[17], ans1, ans2;
       scanf("%d", &ans1);
       for (int i = 1; i <= 4; ++i)
           for (int j = 1; j <= 4; ++j) {
               scanf("%d", &f[i][j]);
               row1[f[i][j]] = i;
           }
       scanf("%d", &ans2);
       for (int i = 1; i <= 4; ++i)
           for (int j = 1; j <= 4; ++j) {
               scanf("%d", &f[i][j]);
               row2[f[i][j]] = i;
           }
       int cnt = 0;
       int num = -1;
       for (int i = 1; i <= 16; ++i)
            if (row1[i] == ans1 && row2[i] == ans2) {
                ++cnt;
                num = i;
            }
       printf("Case #%d: ", tc);
       if (cnt == 1) printf("%d\n", num);
       if (cnt > 1) printf("Bad magician!\n");
       if (cnt == 0) printf("Volunteer cheated!\n");
    }
}
