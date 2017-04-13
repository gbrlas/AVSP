//



#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <math.h>


using namespace std;


template <class T> void out(T x, int n){    for(int i = 0; i < n; ++i)  cout << x[i] << ' ';    cout << endl;   }
template <class T> void out(T x, int n, int m){ for(int i = 0; i < n; ++i)  out(x[i], m);   cout << endl;   }


#define OUT(x) (cout << #x << " = " << x << endl)
#define FOR(i, a, b)    for(int i = (int)a; i < (int)b; ++i)
#define REP(i, b)   FOR(i, 0, b)
#define FORD(i, a, b)   for(int i = (int)a; i >= (int)b; --i)


int maze[110][110];
char ans[110][110];
int vis[110][110];


int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int n, m;

char c;

void dfs(int x, int y, char &cc){
    int px = -1, py, cost = 1000000;
    REP (i, 4)
    {
        int x0 = x + dir[i][0];
        int y0 = y + dir[i][1];
        if (0 <= x0 && x0 < n && 0 <= y0 && y0 < m)
        {
            if (maze[x0][y0] < cost)
            {
                cost = maze[x0][y0];
                px = x0;
                py = y0;
            }

        }
    }
    //printf("[%d %d] -> <%d %d>\n", x, y, px, py);
    if (cost >= maze[x][y])
    {
        cc = c;
        c++;
    }
    else if ('!' == ans[px][py]) dfs(px, py, cc);
    else
    {
        ans[x][y] = ans[px][py];
        cc = ans[px][py];
        return;
    }
    ans[x][y] = cc;
}

int main(){
    int t;
    scanf("%d\n", &t);
    FOR (k, 1, t+1)
    {
        scanf("%d %d\n", &n, &m);
        REP (i, n)
            REP (j, m)
            {
                scanf("%d", &maze[i][j]);
                ans[i][j] = '!';
            }

        c = 'a';
        char cc;
        REP (i, n)
        {
            REP (j, m)
            {
                if ('!' == ans[i][j])
                {
                    dfs(i, j, cc);
                }
            }
        }
        printf("Case #%d:\n", k);
        REP (i, n)
        {
            printf("%c", ans[i][0]);
            FOR (j, 1, m)
            {
                printf(" %c", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

