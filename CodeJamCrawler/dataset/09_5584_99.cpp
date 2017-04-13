#include<iostream>
#include<sstream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<utility>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()

long long tab[501][20];
const string WELCOME("welcome to code jam");
int main(){
  int N;
  cin >> N;
  cin.ignore();
  REP(case_no, N){
    memset(tab, 0, sizeof(tab));
    string s;
    getline(cin, s);
    REP(i, s.size()){
      tab[i][0] = 1;
      FOR(j, 1, 20){
	tab[i+1][j] = tab[i][j];
	if(WELCOME[j-1] == s[i]){
	  tab[i+1][j] = (tab[i+1][j] + tab[i][j-1])%10000;
	}
      }
    }
    printf("Case #%d: %04d\n", case_no+1, tab[s.size()][19]);
  }
  return 0;
}
