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
  int T;
  cin >> T;
  REP(case_no, T){
    string s;
    cin >> s;
    string s_buf = s;
    bool hasNext = next_permutation(ALL(s_buf));
    if(!hasNext){
      s += "0";
      int tail = s.size() - 1;
      while(s[tail] == '0') tail--;
      sort(s.begin(), s.begin() + tail + 1);
      sort(s.begin() + 1, s.end());
    }else next_permutation(ALL(s));
    printf("Case #%d: %s\n", case_no+1, s.c_str());
  }    
  return 0;
}
