#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
template<class T> inline T Max(T a,T b)
{if(a>b)return a;else return b;}
template<class T> inline T Min(T a,T b)
{if(a<b)return a;else return b;}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T TripleMax(T a,T b,T c)
{return Max(Max(a,b),c);}
template<class T> inline T TripleMin(T a,T b,T c)
{return Min(Min(a,b),c);}
typedef long long ll;
typedef long double lde;
// const long double               pi = M_PI;
// const long double               e = M_E;
// const long double               sqrt2 = M_SQRT2;
const long long                 llinfinity = 9223372036854775807LL;
const long long                 llminusinfinity = -9223372036854775808LL;
const int                       intinfinity = 2147483647;
const int                       intminusinfinity = -2147483648;

int         t;
char        board[7][7];

int checkline (int index) {
    int         tnum, xnum, onum;
    tnum = xnum = onum = 0;
    for (int i = 0; i < 4; ++i) {
        if (board[index][i] == 'T') {
            tnum++;
        } else if (board[index][i] == 'X') {
            xnum++;
        } else if (board[index][i] == 'O') {
            onum++;
        }
    }
    if (xnum + tnum == 4 && onum == 0) {
        return 1;
    } else if (tnum + onum == 4 && xnum == 0) {
        return -1;
    } else {
        return 0;
    }
}

int checkrow (int index) {
    int         tnum, xnum, onum;
    tnum = xnum = onum = 0;
    for (int i = 0; i < 4; ++i) {
        if (board[i][index] == 'T') {
            tnum++;
        } else if (board[i][index] == 'X') {
            xnum++;
        } else if (board[i][index] == 'O') {
            onum++;
        }
    }
    if (xnum + tnum == 4 && onum == 0) {
        return 1;
    } else if (tnum + onum == 4 && xnum == 0) {
        return -1;
    } else {
        return 0;
    }
}

int checkdia () {
    int         tnum, xnum, onum;
    tnum = xnum = onum = 0;
    for (int i = 0; i < 4; ++i) {
        if (board[i][i] == 'T') {
            tnum++;
        } else if (board[i][i] == 'X') {
            xnum++;
        } else if (board[i][i] == 'O') {
            onum++;
        }
    }
    if (xnum + tnum == 4 && onum == 0) {
        return 1;
    } else if (tnum + onum == 4 && xnum == 0) {
        return -1;
    }

    tnum = xnum = onum = 0;
    for (int i = 0; i < 4; ++i) {
        if (board[i][3 - i] == 'T') {
            tnum++;
        } else if (board[i][3 - i] == 'X') {
            xnum++;
        } else if (board[i][3 - i] == 'O') {
            onum++;
        }
    }
    if (xnum + tnum == 4 && onum == 0) {
        return 1;
    } else if (tnum + onum == 4 && xnum == 0) {
        return -1;
    } else {
        return 0;
    }
}

void solve () {
    for (int i = 0; i < 4; ++i) {
        gets(board[i]);
    }
    gets(board[4]);

    int         x;
    for (int i = 0; i < 4; ++i) {
        x = checkline(i);
        if (x == 1) printf("X won\n"); else if (x == -1) printf("O won\n");
        if (x != 0) return;
    }
    for (int i = 0; i < 4; ++i) {
        x = checkrow(i);
        if (x == 1) printf("X won\n"); else if (x == -1) printf("O won\n");
        if (x != 0) return;
    }
    x = checkdia();
    if (x == 1) printf("X won\n"); else if (x == -1) printf("O won\n");
    if (x != 0) return;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == '.') {
                printf("Game has not completed\n");
                return;
            }
        }
    }
    printf("Draw\n");
}

int main (int argc, const char* argv[]) {

    // freopen("goodata.in", "r", stdin);
    // freopen("goodata.out", "w", stdout);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    scanf("%d", &t);
    getchar();
    for (int i = 1; i < t + 1; ++i) {
        printf("Case #%d: ", i);
        solve();
    }


    return 0;

}


