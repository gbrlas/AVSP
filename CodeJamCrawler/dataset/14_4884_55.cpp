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
#define deb cout <<"Motha Fucka" <<endl
#define mod 1000000009
using namespace std;
int n, t;
void fi() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
}
vector<int> v;
// ------ template ends ------ //

double c, f, x;
int main() {
  fi();
  int t, l = 1;
  s(t);
  while(t--) {
    sf(c); sf(f); sf(x);
    double tim = 0;
    double rate = 2;
    int cnt = 0;
    while(x/rate > c/rate+x/(rate+f)) {
      cnt++;
      
      tim += c/rate;

      // cout <<c/rate <<" ";
      rate+=f;
    }
    // cout <<endl <<cnt <<endl;
    tim+= x/rate;
    printf("Case #%d: %0.7lf\n", l++, tim);

  }  
  
  return 0;
}