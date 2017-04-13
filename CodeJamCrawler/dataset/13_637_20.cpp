#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int ga[105][105], m, n;

int nota(int r, int c) {
    int p1 = 0, p2 = 0;
    for (int i = 0; i < m; i++) {
        if (ga[i][c] > ga[r][c]) p1++;
    }
    for (int i = 0; i < n; i++) {
        if (ga[r][i] > ga[r][c]) p2++;
    }
    return p1 && p2;
}

int main() {
    freopen("B-small-attempt0.in","r",stdin);
      freopen("out.txt","w+",stdout);
    int c1, c2 = 0;
    scanf("%d", &c1);
    while (c1--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                scanf("%d", ga[i] + j);
            }
        int coun = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                coun += nota(i, j);
        printf("Case #%d: ", ++c2);
        if (coun)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
