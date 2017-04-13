#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
#define inf 0x3f3f3f3f
using namespace std;
int a[50000020][3];
int h[200020];
int v[200020];
int n, m, s, t, r, c;
int tot;
void add(int x, int y, int z) {
    tot++;
    a[tot][0] = h[x];
    a[tot][1] = y;
    a[tot][2] = z;
    h[x] = tot;
    tot++;
    a[tot][0] = h[y];
    a[tot][1] = x;
    a[tot][2] = z;
    h[y] = tot;
}
int bfs() {
    int now, p, i;
    memset(v, 0, sizeof(v));
    v[s] = 1;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        now = q.front();
        q.pop();
        for (i = h[now]; i; i = a[i][0]) {
            if (!v[a[i][1]] && a[i][2]) {
                v[a[i][1]] = v[now] + 1;
                q.push(a[i][1]);
                if (a[i][1] == t)
                    return 1;
            }
        }
    }
    return 0;
}

int dinic(int x, int y) {
    int u = y, k, i;
    if (x == t)
        return y;
    for (i = h[x]; i; i = a[i][0]) {
        if (u && a[i][2] && v[a[i][1]] == v[x] + 1) {
            k = dinic(a[i][1], min(a[i][2], u));
            if (!k)
                v[a[i][1]] = 0;
            u -= k;
            a[i][2] -= k;
            a[i ^ 1][2] += k;
        }
    }
    return y - u;
}
int i, j, k, l, d, ans, dd;
int map[520][520];
int main() {
    int T;
    scanf("%d", &T);
    for (int q = 1; q <= T; q++) {
    //    cerr << q << endl;
        printf("Case #%d: ", q);
        tot = 1;
        memset(h, 0, sizeof h);
        memset(map, 0, sizeof map);
        ans = 0;
        scanf("%d %d %d", &n, &m, &l);
        for (int i = 0; i < l; i++) {
            int x1, x2, y1, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x2++;
            y2++;
            map[x1][y1]++;
            map[x1][y2]--;
            map[x2][y1]--;
            map[x2][y2]++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) {
                    map[i][j] += map[i - 1][j];
                }
                if (j > 0) {
                    map[i][j] += map[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    map[i][j] -= map[i - 1][j - 1];
                }
            }
        }
        s = n * m * 2;
        t = s + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                add((j - 1) * n + i, j * n + i + n * m, 1);
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                add(j * n + (i - 1), j * n + i + n * m, 1);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0) {
                    add(j * n + i + n * m, j * n + i, 1);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            add(s, 0 * n + i + n * m, 1);
            add((n - 1) * n + i, t, 1);
        }
        while (bfs())
            while (dd = dinic(s, inf))
                ans += dd;
        printf("%d\n", ans);
    }
    return 0;
}
