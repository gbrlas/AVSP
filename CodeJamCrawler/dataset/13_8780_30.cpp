#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
 
char mat[10][10];
 
bool check(const char *sp) {
    for ( int i = 0; i < 4; ++i ) {
        int ok = 1;
        for (int j = 0; ok && j < 4; ++j) {
            ok &= strchr(sp, mat[i][j]) != 0;
        }
        if (ok) return true;
    }
    for ( int j = 0; j < 4; ++j ) {
        int ok = 1;
        for (int i = 0; ok && i < 4; ++i) {
            ok &= strchr(sp, mat[i][j]) != 0;
        }
        if (ok) return true;
    }
    do {
        int ok = 1;
        for (int i = 0; ok && i < 4; ++i) {
            ok &= strchr(sp, mat[i][i]) != 0;
        }
        if (ok) return true;
    } while (0);
    do {
        int ok = 1;
        for (int i = 0; ok && i < 4; ++i) {
            ok &= strchr(sp, mat[i][4-1-i]) != 0;
        }
        if (ok) return true;
    } while (0);
    return false;
}
 
bool full() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if ( mat[i][j] == '.' ) return false;
        }
    }
    return true;
}
 
void solve(int ri) {
    for ( int i = 0; i < 4; ++i ) {
        scanf("%s", mat[i]);
    }
    const char *ans;
    if ( check("XT") ) {
        ans = "X won";
    } else if ( check("OT") ) {
        ans = "O won";
    } else if ( full() ) {
        ans = "Draw";
    } else {
        ans = "Game has not completed";
    }
    printf("Case #%d: %s\n", ri, ans);
}
 
int main() {
    freopen("E:/input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int re; cin >> re;
    for ( int ri = 1; ri <= re; ++ri ) solve(ri);
}