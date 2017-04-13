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

void scan_sort(vector <int> &a){
    int answer; scanf("%d", &answer);
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++){
            int x; scanf("%d", &x);
            if (i == answer) a.push_back(x);
        }
    sort(a.begin(), a.end());
}

void solve_case(){
    vector <int> a, b, c(10); a.clear(); b.clear();

    scan_sort(a); scan_sort(b);

    c.resize(set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin()) - c.begin());

    if (c.size() == 0) printf("Volunteer cheated!\n");
    else if (c.size() == 1) printf("%d\n", c[0]);
    else printf("Bad magician!\n");
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
