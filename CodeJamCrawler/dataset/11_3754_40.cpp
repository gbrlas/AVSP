#include <cstdio>
#include <iostream>
using namespace std;
const int MXN = 2001;
char a[100][100];
int n, m;

int main () {
    freopen ("A-small-attempt0.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    int n, m;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        int flag = 1;
        scanf ("%d%d", &n, &m);
        gets (a[0]);
        for (int i = 0; i < n; i++) 
            gets (a[i]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '#') {
                    if (i < n - 1 && j < m - 1 && (a[i + 1][j] == '#') && (a[i + 1][j + 1] == '#') && (a[i][j + 1] == '#')) {
                        a[i][j] = '/';
                        a[i + 1][j] = '\\';
                        a[i][j + 1] = '\\';
                        a[i + 1][j + 1] = '/';
                    } else {
                        flag = 0;
                        break;
                    }
                }
            }
            if (!flag)
                break;
        }
        printf ("Case #%d:\n", ci + 1);
        if (flag) {
            for (int i = 0; i < n; i++)
                puts (a[i]);
        } else
            printf ("Impossible\n");
    }
    return 0;
}
