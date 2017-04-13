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

void solve_case(){
    double c, f, x; scanf("%lf%lf%lf", &c, &f, &x);

    double sol = 2 * x, t = 0;
    for (int farms = 0; farms <= 2 * x; farms++){
        sol = min(sol, t + x / (f * farms + 2));
        t += c / (f * farms + 2);
    }

    printf("%.7lf\n", sol);
}

int main(int argc, char *argv[]){
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);

    int TNUM; scanf("%d", &TNUM);
    for (int T = 1; T <= TNUM; T++){
        printf("Case #%d: ", T);
        solve_case();
    }
    return 0;
}
