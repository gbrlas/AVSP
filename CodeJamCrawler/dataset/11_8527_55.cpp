#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<utility>
#include<iterator>
#include<functional>
#include<iomanip>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<climits>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

int main(){
  int T; cin >> T;
  REP(case_no, T){
    int n;
    cin >> n;
    long double WP[n];
    long double OWP[n];
    long double OOWP[n];
    string field[n];
    REP(i, n){
      cin >> field[i];
      int total(0), win(0);
      REP(j, n){
	if(field[i][j] == '1'){
	  win++;
	  total++;
	}else if(field[i][j] == '0'){
	  total++;
	}
      }
      WP[i] = total ? (long double) win / total : 0.0;
    }

    REP(i, n){
      int total(0);
      long double sum(0.0);
      REP(j, n){
	if(field[i][j] != '.'){
	  total++;
	  long double temp(0.0);
	  int x(0);
	  REP(k, n){
	    if(k != i && field[j][k] != '.') x++;
	    if(k != i && field[j][k] == '1') temp += 1.0;
	  }
	  sum += temp/x;
	}
      }
      OWP[i] = total ? sum / total : 0.0;
    }

    REP(i, n){
      int total(0);
      long double sum(0.0);
      REP(j, n){
	if(field[i][j] != '.'){
	  total++;
	  sum += OWP[j];
	}
      }
      OOWP[i] = total ? sum / total : 0.0;
    }
    printf("Case #%d:\n", case_no+1);
    REP(i, n){
      printf("%.8lf\n", (double)(0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP[i]));
    }
  }
  return 0;
}
