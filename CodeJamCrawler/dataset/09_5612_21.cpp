#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<deque>
#include<stack>

#include<algorithm>
#include<utility>
#include<functional>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cmath>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define MP make_pair

int main(){
  int T, N;
  cin >> T;
  REP(case_no, T){
    cin >> N;
    int dat[N];
    string s;
    memset(dat, 0, sizeof(dat));
    REP(i,N){
      cin >> s;
      REP(j, N) if(s[j] == '1') dat[i] = j;
    }
    int ans(0);
    REP(i,N){
      int idx = -1;
      REP(j, N) if(dat[j] <= i){idx = j; break;}
      ans += idx - i;
      for(int j = idx; j > i; j--) swap(dat[j], dat[j-1]);
      dat[i] = 65535;
    }
    printf("Case #%d: %d\n", case_no+1, ans);
  }
  return 0;
}
