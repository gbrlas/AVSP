#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
template<class T> inline T Max(T a,T b)
{if(a>b)return a;else return b;}
template<class T> inline T Min(T a,T b)
{if(a<b)return a;else return b;}
template<class T> inline T gcd(T a,T b)
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T TripleMax(T a,T b,T c)
{return Max(Max(a,b),c);}
template<class T> inline T TripleMin(T a,T b,T c)
{return Min(Min(a,b),c);}
typedef long long ll;
typedef long double lde;
// const long double               pi = M_PI;
// const long double               e = M_E;
// const long double               sqrt2 = M_SQRT2;
const long long                 llinfinity = 9223372036854775807LL;
const long long                 llminusinfinity = -9223372036854775808LL;
const int                       intinfinity = 2147483647;
const int                       intminusinfinity = -2147483648;

int             t, ans;
ll              num[100] = {0,1,4,9,121,484,676,10201,12321,14641,40804,44944,69696,94249,698896,1002001,1234321,4008004,5221225,6948496,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,522808225,617323716,942060249,10000200001,10221412201,12102420121,12345654321,40000800004,637832238736,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1086078706801,1210024200121,1212225222121,1214428244121,1230127210321,1232346432321,1234567654321,1615108015161,4000008000004,4004009004004,4051154511504,5265533355625,9420645460249,llinfinity};
ll              a, b;
vector<ll>      rets;

int judge (ll a) {
    ll          x = a;
    int         nums[100];
    int         pt = -1;
    while (x > 0) {  
        pt++;  
        nums[pt] = x % 10;
        x = x / 10;
    }
    int         pt2 = 0;
    while (pt2 < pt) {    
        if (nums[pt2] != nums[pt]) {
            return 0;
        }
        pt2++; pt--;
    }
    return 1;
}

void solve () {
    rets.clear();
    for (int i = 0; i < 61; ++i) {
        ll      q = (ll)sqrt(num[i]);
        // printf("q = %lld, num[i] = %lld\n", q, num[i]);
        if (judge(q) == 1) {
            rets.push_back(num[i]);
        }
    }
}

void search (ll a, ll b) {
    int         ans = 0;
    for (int i = 0; i < rets.size(); ++i) {
        if (rets[i] <= b && rets[i] >= a) {
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main (int argc, const char* argv[]) {

    // freopen("goodata.in", "r", stdin);
    // freopen("goodata.out", "w", stdout);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    scanf("%d", &t); ans = 0;

    solve();
    while (t--) {    
        scanf("%lld%lld", &a, &b);
        printf("Case #%d: ", ++ans);
        search(Min(a, b), Max(a, b));
    }


    return 0;

}


