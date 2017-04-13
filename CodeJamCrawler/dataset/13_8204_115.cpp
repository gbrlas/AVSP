#include <string>	
#include <string.h>
#include <cstdio>	
#include <iostream>	
#include <memory>	
#include <cstdlib>	
#include <cmath>	
#include <algorithm>
#include <set>		
#include <map>		
#include <vector>
#include <ctime>	
#include <cassert>

using namespace std;

#if ( _WIN32 || __WIN32__ || _WIN64 || __WIN64__ )
#define I64 "%I64d"
#else
#define I64 "%Ld"
#endif

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define dbg(x) cerr << #x << " = " << (x) << endl
#define fori(i,b,e) for(int i = (b); i < (e); i++)
#define forall(p,s) for(typeof((s).begin()) p = (s).begin(); p != (s).end(); p++)
#define memclr(a) memset((a), 0, sizeof(a))
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define fi first
#define se second

typedef long double ldb;
typedef long long int64;

#define PROBLEM_NAME "a"

char s[4][5];

bool win(char c) {
    bool flag;
    fori(i,0,4) {
        flag = true;
        fori(j,0,4) {
            if (s[i][j] != c && s[i][j] != 'T') {
                flag = false;
                break;
            }
        }
        if (flag) return true;
        flag = true;
        fori(j,0,4) {
            if (s[j][i] != c && s[j][i] != 'T') {
                flag = false;
                break;
            }
        }
        if (flag) return true;
    }
    flag = true;
    fori(i,0,4) {
        if (s[i][i] != c && s[i][i] != 'T') {
            flag = false;
            break;
        }
    }
    if (flag) return true;
    flag = true;
    fori(i,0,4) {
        if (s[i][3-i] != c && s[i][3-i] != 'T') {
            flag = false;
            break;
        }
    }
    if (flag) return true;
    return false;
}

bool finished() {
    fori(i,0,4) {
        fori(j,0,4) {
            if (s[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

string calc() {
    fori(i,0,4) {
        scanf("%s", s[i]);
    }
    if (win('X')) {
        if (win('O')) {
            return "Draw";
        } else {
            return "X won";
        }
    } else {
        if (win('O')) {
            return "O won";
        } else if (finished()) {
            return "Draw";
        } else {
            return "Game has not completed";
        }
    }
}

int main () {
	freopen (PROBLEM_NAME ".in", "rt", stdin);
	freopen (PROBLEM_NAME ".out", "wt", stdout);
    int TT;
    scanf ("%d\n", &TT);
    for (int tt = 1; tt <= TT; ++tt) {
        printf("Case #%d: ", tt);
        cout << calc();
        printf ("\n");
    }	
	return 0;
}
