#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#include <memory>

#define sz(a) ((int)(a).size())
#define fori(i,b,e) for(int i = (b); i < (e); ++i)
#define pb push_back
#define mp make_pair

typedef long double ldb;
typedef long long int64;

using namespace std;
int64 a[48];

int get(int n) {
    fori(i,0,48) {
        if (a[i] > n) {
            return i;
        }
    }
}

int main() {
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    a[0] = 1L;
    a[1] = 4L;
    a[2] = 9L;
    a[3] = 121L;
    a[4] = 484L;
    a[5] = 10201L;
    a[6] = 12321L;
    a[7] = 14641L;
    a[8] = 40804L;
    a[9] = 44944L;
    a[10] = 1002001L;
    a[11] = 1234321L;
    a[12] = 4008004L;
    a[13] = 100020001L;
    a[14] = 102030201L;
    a[15] = 104060401L;
    a[16] = 121242121L;
    a[17] = 123454321L;
    a[18] = 125686521L;
    a[19] = 400080004L;
    a[20] = 404090404L;
    a[21] = 10000200001LL;
    a[22] = 10221412201LL;
    a[23] = 12102420121LL;
    a[24] = 12345654321LL;
    a[25] = 40000800004LL;
    a[26] = 1000002000001LL;
    a[27] = 1002003002001LL;
    a[28] = 1004006004001LL;
    a[29] = 1020304030201LL;
    a[30] = 1022325232201LL;
    a[31] = 1024348434201LL;
    a[32] = 1210024200121LL;
    a[33] = 1212225222121LL;
    a[34] = 1214428244121LL;
    a[35] = 1232346432321LL;
    a[36] = 1234567654321LL;
    a[37] = 4000008000004LL;
    a[38] = 4004009004004LL;
    a[39] = 100000020000001LL;
    a[40] = 100220141022001LL;
    a[41] = 102012040210201LL;
    a[42] = 102234363432201LL;
    a[43] = 121000242000121LL;
    a[44] = 121242363242121LL;
    a[45] = 123212464212321LL;
    a[46] = 123456787654321LL;
    a[47] = 400000080000004LL;
    int TT;
    scanf ("%d\n", &TT);
    for (int tt = 1; tt <= TT; ++tt) {
        printf("Case #%d: ", tt);
        int64 a, b;
        cin >> a >> b;
        cout << get(b) - get(a-1);
        printf ("\n");
    }
}
