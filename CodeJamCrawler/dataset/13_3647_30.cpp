#include <cstdio>
#include <vector>
using std::vector;
int T;
char a[5][5];
vector<int> p;
vector<int> q;
int result;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            p.push_back(i);
            q.push_back(j);
        }
        for (int j = 0; j < 4; j ++) {
            p.push_back(j);
            q.push_back(i);
        }
    }
    for (int i = 0; i < 4; i ++) {
        p.push_back(i);
        q.push_back(i);
    }
    for (int i = 0; i < 4; i ++) {
        p.push_back(i);
        q.push_back(3 - i);
    }
    for (int ci = 1; ci <= T; ci ++) {
        for (int i = 0; i < 4; i ++)
            scanf("%s", a[i]);
        result = 1;
        for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++)
                if (a[i][j] == '.')
                    result = 0;
        for (int i = 0; i < 10; i ++) {
            int x = 0;
            int y = 0;
            int z = 0;
            for (int j = i * 4; j < i * 4 + 4; j ++) {
                char t = a[p[j]][q[j]];
                if (t == 'X')
                    x ++;
                else if (t == 'O')
                    y ++;
                else if (t == 'T')
                    z = 1;
            }
            x += z;
            y += z;
            if (x == 4)
                result = 2;
            else if (y == 4)
                result = 3;
        }
        if (result == 0)
            printf("Case #%d: Game has not completed\n", ci);
        else if (result == 1)
            printf("Case #%d: Draw\n", ci);
        else if (result == 2)
            printf("Case #%d: X won\n", ci);
        else if (result == 3)
            printf("Case #%d: O won\n", ci);
    }
}
