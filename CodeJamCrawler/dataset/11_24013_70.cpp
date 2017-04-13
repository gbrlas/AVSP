#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int combine[100][100], oppose[100][100];
char stock[102];
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, n, c, d, i, j;
    char str[5];
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d", &c);
        memset(combine, 0, sizeof(combine));
        memset(oppose, 0, sizeof(oppose));
        for (i = 0; i < c; i++) {
            scanf("%s", str);
            combine[str[0]][str[1]] = str[2];
            combine[str[1]][str[0]] = str[2];
        }
        scanf("%d", &d);
        for (i = 0; i < d; i++) {
            scanf("%s", str);
            oppose[str[0]][str[1]] = 1;
            oppose[str[1]][str[0]] = 1;
        }
        scanf("%d%s", &n, str);
        int head = 0, tail = 1, j, flg;
        char element;
        stock[0] = str[0];
        for (i = 1; i < n; i++) {
            element = str[i];
            if (combine[element][stock[tail-1]]) {
                stock[tail-1] = combine[element][stock[tail-1]];
                continue;
            }
            flg = 1;
            for (j = head; j < tail; j++) {
                if (oppose[element][stock[j]]) {
                    tail = 0;
                    flg = 0;
                }
            }
            if (flg)
                stock[tail++] = element;
        }
        printf("Case #%d: [", cas);
        for (i = head; i < tail-1; i++) {
            printf("%c, ", stock[i]);
        }
        if (tail > 0)
            printf("%c]\n", stock[tail-1]);
        else
            printf("]\n");
    }
    return 0;
}
