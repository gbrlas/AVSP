#include <cstdio>
#include <cstring>
using namespace std;
int h[102][102], n, m;
bool ok() {
    bool flag;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        flag = true;
        for (int k=0; k<n; k++) if (h[i][j] < h[k][j]) { flag = false; break; }
        if (flag) continue;
        flag = true;
        for (int k=0; k<m; k++) if (h[i][j] < h[i][k]) { flag = false; break; }
        if (flag) continue; else return false;
    }
    return true;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);


    int T;
    scanf("%d", &T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%d%d", &n, &m);
        printf("Case #%d: ", cas);
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", &h[i][j]);
        if (ok()) printf("YES\n");
        else printf("NO\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
