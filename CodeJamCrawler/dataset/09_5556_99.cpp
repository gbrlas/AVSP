#include<iostream>
#include<sstream>
#include<vector>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()


int main(){
  int L, D, N;
  cin >> L >> D >> N;
  cin.ignore();
  string dat[D];
  bool exist[L][256];
  REP(i, D) cin >> dat[i];

  REP(case_no, N){
    memset(exist, 0, sizeof(exist));
    string s;
    cin >> s;
    for(int i = 0, idx = 0; i < s.size(); i++, idx++){
      if(s[i] == '('){
	while(s[i] != ')') exist[idx][(int)s[i++]] = true;
      }else{
	exist[idx][(int)s[i]] = true;
      }      
    }
    
    int ans(0);
    REP(i, D) {
      bool ok = true;
      REP(j, L) if(!exist[j][(int)dat[i][j]]) { ok = false; break;}
      if(ok) ans++;
    }

    printf("Case #%d: %d\n", case_no+1, ans);
  }
  return 0;
}
