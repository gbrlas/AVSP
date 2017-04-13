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
int a[11][11];

bool c_row (int x, int row)
{
    int i;
    for (i = 0; i < row; i++) {
        if (a[i][x] == 2 ){
            return false;
        }
    }
    return true;
}

bool c_column (int x, int column)
{
    int i;
    for (i = 0; i < column; i++) {
        if (a[x][i] == 2) {
            return false;
        }
    }
    return true;
}

void ff (int row, int column)
{
    int i,j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            if (a[i][j] == 2) {
                continue;
            }
            if (c_row (j, row) || c_column (i, column)) {
                continue;
            }
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main()
{
    int t,ii,i,j,n,m;
    ii = 1;
    freopen("iii.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;

    while (t--) {
       cin >> n >> m;
       for (i = 0; i < n; i++) {
           for (j = 0; j < m; j++) {
               cin >> a[i][j];
           }
       }
       cout << "Case #" << ii << ": ";
       ii++;
       ff (n, m);

    }
    return 0;
}
