#include <cstdio>
#include <cstring>
using namespace std;
char g[4][4];
bool judge(char ch) {
    int cnt;
    for (int i=0; i<4; i++) {
        cnt = 0;
        for (int j=0; j<4; j++) if (g[i][j] == ch || g[i][j] == 'T') cnt++;
        if (cnt == 4) return true;
        cnt = 0;
        for (int j=0; j<4; j++) if (g[j][i] == ch || g[j][i] == 'T') cnt++;
        if (cnt == 4) return true;
    }
    cnt = 0;
    for (int i=0; i<4; i++) if (g[i][i] == ch || g[i][i] == 'T') cnt++;
    if (cnt == 4) return true;
    cnt = 0;
    for (int i=0; i<4; i++) if (g[i][3-i] == ch || g[i][3-i] == 'T') cnt++;
    if (cnt == 4) return true;

}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    scanf(" %d", &T);
    for (int cas=1; cas<=T; cas++) {
        int cnt = 0;
        for (int i=0; i<4; i++) for (int j=0; j<4; j++) {
            scanf(" %c", &g[i][j]);
            if (g[i][j] == '.') cnt++;
        }
        bool x = judge('X');
        bool o = judge('O');
        printf("Case #%d: ", cas);
        if (x) printf("X won\n");
        else if (o) printf("O won\n");
        else if (cnt == 0) printf("Draw\n");
        else printf("Game has not completed\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
