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

double a[1005], b[1005];
int dw() {
  int ans = 0;
  int idx1 = 0, idx2 = 0;
  while (idx1 < n && idx2 < n) {
    while(a[idx1] < b[idx2]) {
      
      idx1++;
      if(idx1 >= n || idx2 >= n) break;
    }
    if(idx1 >= n || idx2 >= n) break;
    // cout << idx1 <<" " << idx2 <<endl;
    idx2++;
    idx1++;
    ans++;
  }
  return ans;
}
int w(){
  int ans = 0;
  int sa = 0, sb = 0, ea = n-1, eb = n-1;
  while(sa <= ea && sb <= eb) {
    if(a[ea] < b[eb]){
      eb--;
      ea--;
    } else {
      ans++;
      ea--;
      sb++;
    }
  }
  return ans;
}
int main() {
  fi();
  int t, l = 1;
  s(t);
  while(t--) {
    s(n);
    forall(i, 0, n) 
      sf(a[i]);
    forall(i, 0 ,n) 
      sf(b[i]);

    sort(a, a+n);
    sort(b, b+n);
    // forall(i, 0, n) cout << a[i] <<" "; cout <<endl;
    // forall(i, 0, n) cout << b[i] <<" "; cout <<endl;
    printf("Case #%d: %d %d\n", l++, dw(), w());


  }
  return 0;
}