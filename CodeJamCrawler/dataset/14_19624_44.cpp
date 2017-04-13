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

int TC;
double C, F, X;

double cal(double C, double f, double F, double X){
    double first, second;

    first = X / f;
    second = X / (f + F) + C / f;
    //cout << first << " " << second << endl;
    if (first < second)
        return first;
    else
        return cal(C, f + F, F, X) + C / f;

}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("Test.OUT", "w", stdout);
    #endif // ONLINE_JUDGE

    read(TC);
    fr(caseNo, 1, TC){
        scanf("%lf %lf %lf", &C, &F, &X);
        printf("Case #%d: %.7lf\n", caseNo, cal(C, 2, F, X));
    }

    return 0;
}

