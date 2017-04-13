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
#define maxN 1005

int TC, n;
double Naomi[maxN], Ken[maxN];
bool used[maxN];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("Test.OUT", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> TC;
    fr(caseNo, 1, TC){
        cin >> n;
        rep(i, n) cin >> Naomi[i];
        rep(i, n) cin >> Ken[i];
        sort(Naomi, Naomi + n);
        sort(Ken, Ken + n);
        //rep(i, n) cout << Naomi[i] << " "; cout << endl;
        //rep(i, n) cout << Ken[i] << " "; cout << endl;
        rep(i, maxN) used[i] = false;
        int point1 = 0, point2 = n;
        rep(i, n){
            rep(j, n){
                if (!used[j] && Ken[j] > Naomi[i]){
                    used[j] = true;
                    point2--;
                    break;
                }
            }
        }
        rep(i, maxN) used[i] = false;
        for (int i = n -1; i >= 0; i--){
            for (int j = n - 1; j >= 0; j--){
                if (!used[j] && Naomi[i] > Ken[j]){
                    used[j] = true;
                    point1++;
                    break;
                }
            }
        }

        printf("Case #%d: %d %d\n", caseNo, point1, point2);
    }

    return 0;
}
