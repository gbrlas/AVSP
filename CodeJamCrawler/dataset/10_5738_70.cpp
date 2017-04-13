#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>
#include<iterator>
#include<functional>

#include<cstdio>
#include<cstdlib>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

#define MOD 100003

int memo[501][501];
int f(int number, int position){
  int& ret(memo[number][position]);
  if(ret >= 0) return ret;
  else if(position == number){
    return 0;
  }
  else if(position <= 1){
    return 1;
  }else if(number <= 2){
    return 0;
  }

  ret = 0;
  //  for(int i = number-1; i >= 2 && i >= position-1; i--){
  //  int 
  int x = 1;
  int n = max(0, (number-position-1));
  for(int i = position-1, j = 0; i >= 1; i--, j++){
    ret = (ret + f(position,  i) % MOD * x % MOD) % MOD;
    x = x * (n - j) / (j+1);
  }
  return ret;
}

int main(){
  int T;
  cin >> T;
  REP(case_no, T){
    int n;
    cin >> n;
    REP(i, n+1)REP(j, n+1) memo[i][j] = -1;
    int ans(0);
    REP(i, n){
      ans = (ans + f(n, i+1)) % MOD;
      //      cerr << i+1 << " " << ans << endl;
    }
    cout << "Case #" << case_no+1 << ": " << ans << endl;
  }
  return 0;
}
