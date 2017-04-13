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

int a[10][10], b[10][10], x, y;
int main() {
  fi();
  int t, l = 1;
  s(t);
  while(t--) {
    s(x);
    x--;
    forall(i, 0, 4) {
      forall(j, 0, 4) {
        s(a[i][j]);
      }
    }
    s(y);
    y--;
    forall(i, 0, 4) {
      forall(j, 0, 4) {
        s(b[i][j]);
      }
    }
    int cnt = 0, ans = -1;
    forall(i, 0, 4) {
      forall(j, 0, 4) {
        if(a[x][i] == b[y][j]){
          ans = a[x][i];
          cnt++;
        }
      }
    }
    printf("Case #%d: ", l++);
    if(cnt == 1) {
      printf("%d\n", ans);
    } else if (cnt > 1) {
      printf("Bad magician!\n");
    } else{
      printf("Volunteer cheated!\n");
    }
  }
  return 0;
}