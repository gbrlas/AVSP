/* Jai Gupta */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <set>
#include <sstream>

using namespace std;

#define oo 0x7F7F7F7F
#define LET(x,a)     __typeof(a) x(a)
#define EACH(it,v)   for(LET(it,v.begin());it!=v.end();++it)
#define REP(i,n)     for(__typeof(n) i(0); i<n; i++)
#define ALL(x)       (x).begin(), (x).end()
#define gint(t)      scanf("%d", &t);
#define pint(t)      printf("%d\n", t);
#define pb           push_back
#define mp           make_pair
#ifdef JAI_ARENA
#define debug(args...) {cerr<<"> "; dbg,args;cerr<<endl;}
#define debugv(v, n)      {cerr<<"> "; REP(ni, n) dbg,v[ni]; cerr<<endl;}
#else
#define debug(...) ;
#define debugv(...) ;
#endif
typedef long long int   ll;
typedef unsigned long long int ull;
typedef unsigned int    uint;
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<vi>      vii;
typedef vector<pii>     vpii;

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;


#define BUF 4096
char ibuf[BUF];
int ipt = BUF;

int readUInt() {
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] < '0') ipt++;
    }
    int n = 0; char neg = 0;
    if(ipt !=0 && ibuf[ipt-1] == '-') neg = 1;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    if (ipt == BUF) {
    fread(ibuf, 1, BUF, stdin);
    ipt = 0;
    while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
    }
    return neg?-n:n;
}
int testcase;
char v[10][10];
bool won_x()
{
    for(int i = 0; i < 4; i++) {
        bool won = true;
        for(int j = 0; j < 4; j++) {
            if(v[i][j] !='X' && v[i][j] != 'T') {
                won = false;
                break;
            }
        }
        if(won) return true;
    }
    for(int i = 0; i < 4; i++) {
        bool won = true;
        for(int j = 0; j < 4; j++) {
            if(v[j][i] !='X' && v[j][i] != 'T') {
                won = false;
                break;
            }
        }
        if(won) return true;
    }
    bool won = true;
    for(int j = 0; j < 4; j++) {
        if(v[j][j] !='X' && v[j][j] != 'T') {
            won = false;
            break;
        }
    }
    if(won) return true;
    won = true;
    for(int j = 0; j < 4; j++) {
        if(v[j][3-j] !='X' && v[j][3-j] != 'T') {
            won = false;
            break;
        }
    }
    if(won) return true;
    return false;
}

bool won_o()
{
    for(int i = 0; i < 4; i++) {
        bool won = true;
        for(int j = 0; j < 4; j++) {
            if(v[i][j] !='O' && v[i][j] != 'T') {
                won = false;
                break;
            }
        }
        if(won) return true;
    }
    for(int i = 0; i < 4; i++) {
        bool won = true;
        for(int j = 0; j < 4; j++) {
            if(v[j][i] !='O' && v[j][i] != 'T') {
                won = false;
                break;
            }
        }
        if(won) return true;
    }
    bool won = true;
    for(int j = 0; j < 4; j++) {
        if(v[j][j] !='O' && v[j][j] != 'T') {
            won = false;
            break;
        }
    }
    if(won) return true;
    won = true;
    for(int j = 0; j < 4; j++) {
        if(v[j][3-j] !='O' && v[j][3-j] != 'T') {
            won = false;
            break;
        }
    }
    if(won) return true;
    return false;
}
bool game_completed()
{
    for(int i = 0;  i < 4; i++)
    {
        for(int j = 0; j < 4; j++) {
            if(v[i][j] == '.') return false;
        }
    }
    return true;
}
int tcase;
void solve() {
    string res;
    if(won_x()) {
        res = "X won";
    } else if(won_o()) {
        res = "O won";
    } else if(game_completed()) {
        res = "Draw";
    } else {
        res = "Game has not completed";
    }
    printf("Case #%d: %s\n", tcase, res.c_str());
}
bool input() {
    scanf("%s", v[0]);
    scanf("%s", v[1]);
    scanf("%s", v[2]);
    scanf("%s", v[3]);
    return true;
}
void preprocess() {

}
int main()
{
    preprocess();
    gint(testcase);
    for(tcase = 1; tcase <= testcase; tcase++)
        if(input())
                solve();
    return 0;
}
