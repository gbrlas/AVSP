#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <climits>
#define pb push_back

#define ill long long int
#define ull unsigned long long int
#define pii pair<int,int>
#define INF (int)1e9
#define s(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define sf(n) scanf("%lf", &n)
#define su(n) scanf("%llu", &n)
// #define S(n) scanf("%d", &n)
#define S1(n) scanf("%lld", &n)
#define sl(n) scanf("%lld", &n)
#define Su(n) scanf("%llu", &n)
#define pb push_back
#define F(i,a,b) for(int i=(a); i<(b); i++)
#define forall(i,a,b) for(int i=(a); i<(b); i++)
#define mem(a, v) memset(a, v, sizeof(a))
#define M(a,v) memset(a, v, sizeof(a))
#define all(v) v.begin(),v.end()
#define fr first
#define sec second
#define deb cout <<"coink" <<endl
#define mod 1000000007
#define MAX 2
using namespace std;
int  t;
void fi() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
}
vector<string> v;
// ------ template ends ------ //
string res;
int main() {
  fi();
  int t;
  s(t);
  int l = 1;
  while(t--) {

    int a, b, kk;
    s(a); s(b); s(kk);
    int cnt = 0;
    forall(i, 0, a) {
      forall(j, 0, b) {
        if((i&j) < kk) {
          cnt++;
        }
      }
    }
    printf("Case #%d: %d\n", l++, cnt);
  }
}