#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include <ctime>
#include <assert.h>
using namespace std;

#define PI 3.141592653589793
#define INF 2123456789
#define NUL 0.0000001

#define for_each(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define SZ size()
#define CS c_str()
#define PB push_back
#define MP make_pair
#define INS insert
#define EMP empty()
#define CLR clear()
#define LEN length()
#define MS(x) memset(x, 0, sizeof(x))
#define MS1(x) memset(x, -1, sizeof(x))

typedef long long LL;
typedef unsigned long long ULL;

char table[10][10];

int check(int x, int y, int dx, int dy){
    int cntX = 0, cntO = 0, cntT = 0;
    for (int i = 0; i < 4; i++){
        if (table[x][y] == 'X') cntX++;
        if (table[x][y] == 'O') cntO++;
        if (table[x][y] == 'T') cntT++;
        x += dx; y += dy;
    }
    if (cntX == 4 || cntX == 3 && cntT) return 1;
    if (cntO == 4 || cntO == 3 && cntT) return 2;
    return 0;
}

int main(){
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int _t; scanf("%d", &_t);
    for (int t = 1; t <= _t; t++){
        for (int i = 0; i < 4; i++) scanf("%s", table[i]);

        int sol = 0;
        for (int i = 0; i < 4; i++){
            sol |= check(i, 0, 0, 1);
            sol |= check(0, i, 1, 0);
        }
        sol |= check(0, 0, 1, 1);
        sol |= check(3, 0, -1, 1);

        string print;
        if (sol == 1)
            print = "X won";
        else if (sol == 2)
            print = "O won";
        else {
            bool tablaufullu = true;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    tablaufullu &= table[i][j] != '.';
            if (tablaufullu)
                print = "Draw";
            else
                print = "Game has not completed";
        }

        printf("Case #%d: %s\n", t, print.CS);
    }
    return 0;
}
