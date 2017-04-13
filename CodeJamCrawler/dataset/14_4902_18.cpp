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

bool check() {
  res = string("");
  string str = v[0];
  forall(i, 0, str.size()-1) {
    if(str[i]== str[i+1]) continue;
    res.pb(str[i]);
  }
  res.pb(str[str.size()-1]);
  // cout << res <<endl;
  forall(i, 1, v.size()) {
    string res1;
    string str = v[i];
    forall(j, 0, str.size()-1) {
      if(str[j]== str[j+1]) continue;
      res1.pb(str[j]);
    }
    res1.pb(str[str.size()-1]);
    // cout << res1 <<endl;
    if(res != res1) {
      return true;
    }
  }
  return false;
}
vector<int> num[500];
int main() {
  fi();
  int  n;
  int l  =1;
  s(t);
  while(t--) {

    v.clear();
    s(n);
    forall(i, 0, n) num[i].clear();
    string str;
    forall(i, 0, n) {
      cin >> str;
      v.pb(str);
    }
    

    if(check()) {
      printf("Case #%d: ", l++);
      printf("Fegla Won\n");
      continue;
    }
    forall(i, 0, n) {
      string str = v[i];
      int cnt = 0;

      forall(j, 0, str.size()) {
        if(str[j] == str[j+1]) {
          cnt++;
          continue;
        }
        num[i].pb(cnt+1);
        // cout << cnt +1<< " ";
        cnt = 0;
      }
      // cout <<endl;
    }
    int res = 0;
    forall(i, 0, num[0].size()) {
      int sum = 0;
      forall(j, 0, n) {
        sum += num[j][i];
      }
      sum /=n;
      // cout << "===" <<sum <<endl;
      int diff = 0;
      forall(j, 0, n) {
        diff+= abs(num[j][i] - sum);
      }
      res+= diff;
      // cout << "=---" <<diff <<endl;
    }
    printf("Case #%d: ", l++);
    printf("%d\n", res);
  }


}