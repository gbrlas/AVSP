#include <iostream>
#include <cstring>
#include <set>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <queue>
#define mod  747474747
using namespace std;
vector <string> s (4);
bool check ()
{
    int i,j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (s[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}
bool row (char ch)
{
    int i,j,flag=0;
    for (i = 0; i < 4; i++) {
        flag = 0;
        for (j = 0; j < 4; j++) {
            if (s[i][j] == ch || s[i][j] == 'T') {
                continue;
            }
            flag = 1;
            break;
        }
        if (flag == 0) {
            return true;
        }
    }
    return false;
}

bool column (char ch)
{
    int i,j,flag=0;
    for (i = 0; i < 4; i++) {
        flag = 0;
        for (j = 0; j < 4; j++) {
            if (s[j][i] == ch || s[j][i] == 'T') {
                continue;
            }
            flag = 1;
            break;
        }
        if (flag == 0) {
            return true;
        }
    }
    return false;
}


bool diagonal (char ch)
{
    int i,flag=0;
    for (i = 0; i < 4; i++) {
        if (s[i][i] == ch || s[i][i] == 'T') {
            continue;
        }
        flag = 1;
        break;
    }
    if (flag == 0) {
        return true;
    }
    int j;
    i = 0;
    j = 3;
    while (i != 4) {
        if (s[i][j] == ch || s[i][j] == 'T') {
            i++;
            j--;
            continue;
        }
        return false;
    }
    return true;
}


int main()
{
    int t,i,ii;
    ii = 1;
    freopen("input1.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;
    while (t--) {
        for (i = 0; i < 4; i++) {
            cin >> s[i];
        }
        cout << "Case #" << ii << ": ";
        ii++;
        if (row ('O')) {
            cout << "O won" << endl;
            continue;
        }
        if (row ('X')) {
            cout << "X won" << endl;
            continue;
        }

        if (column ('O')) {
            cout << "O won" << endl;
            continue;
        }
        if (column ('X')) {
            cout << "X won" << endl;
            continue;
        }

        if (diagonal ('O')) {
            cout << "O won" << endl;
            continue;
        }
        if (diagonal ('X')) {
            cout << "X won" << endl;
            continue;
        }

        if (check ()) {
            cout << "Draw" << endl;
            continue;
        }
        cout << "Game has not completed" << endl;
    }
    return 0;
}
