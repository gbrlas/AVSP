//-----------------------------------------
// Le Truong Quoc Thang
// ltqthang@gmail.com
// Problem:
// ----------------------------------------

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define write(a) printf("%d", a)
#define writes(a) printf("%d ", a)
#define writeln(a) printf("%d\n", a)
#define read(a) scanf("%d", &a)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define mii map <int, int>
#define INF 2000000000
#define maxN 1000005

int TC, n1, n2;
int a[10][10], b[10][10];
mii row;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("Test.OUT", "w", stdout);
    #endif // ONLINE_JUDGE

    read(TC);
    rep(caseNo, TC){
        row.clear();
        int cnt = 0;
        read(n1);
        rep(i, 4) rep(j, 4) read(a[i][j]);
        read(n2);
        rep(i, 4) rep(j, 4) read(b[i][j]);

        rep(i, 4) row[a[n1 - 1][i]] = 1;
        rep(i, 4) if (row[b[n2 - 1][i]]) cnt++;
        //cout << cnt << " ";
        printf("Case #%d:", caseNo + 1);
        if (cnt == 0){
            puts(" Volunteer cheated!");
        }
        else{
            if (cnt > 1){
                puts(" Bad magician!");
            }
            else{
                rep(i, 4) if (row[b[n2 - 1][i]]) printf(" %d\n", b[n2 - 1][i]);
            }
        }
    }

    return 0;
}
