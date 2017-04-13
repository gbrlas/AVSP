#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>

#include<tr1/unordered_map>
#include<tr1/unordered_set>

#include<algorithm>
#include<functional>
#include<utility>
#include<iomanip>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>

using namespace std;

#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define MP make_pair

const long double eps(1.0e-12);

long double memo[1001][1001];
long double dfs(const int& n, int remain, int chain){
  long double& ret = memo[remain][chain];
  if(ret > -eps){
    return ret;
  }else if(remain <= 1){
    if(chain > 0){
      if(chain+1 < n) return dfs(chain+1, chain+1, 0);
      else          return 0.0;
    }else{
      return ret = 1.0;
    }
  }
  ret = 0;
  if(chain == 0){
    ret = dfs(n, remain-1, 0) / remain; //2.0 / 3
  }else{
    ret = (dfs(n, remain-1, 0) + dfs(chain+1, chain+1, 0)) / (double)remain;
  }
  ret += dfs(n, remain-1, chain+1) * (remain-1.0)/remain; // * 2/3
  return ret;
}

double getscore(int elem){
  //return (elem-1) * 2;
  return elem >= 2 ? dfs(elem, elem, 0) : 0;
}

long double getlim(int x, long double p){
  long double inv_x = 1.0 / x;
  long double rest = 1.0 - inv_x;
  long double ret(0), rate(1.0);
  REP(i, 100000){
    ret += (p + i*rest) * rate;
    rate *= inv_x;
  }
  return ret;
}


int main(){
  REP(i, 1001)REP(j, 1001) memo[i][j] = -1.0;
  FOR(i, 2, 1001) {
    long double temp = getscore(i);
    memo[i][0] = getlim(i, temp);
#ifdef DEBUG
    if(i <= 10)cerr << "!" << i << " " << temp << " " << memo[i][0] << endl;
#endif
  }
  int T;
  cin >> T;
  REP(case_no, T){
    int N;
    cin >> N;
    int dat[N];
    REP(i, N){
      cin >> dat[i]; dat[i]--;
    }
    long double ans = 0;
    REP(i, N){
	int start = dat[i], now = dat[i];
	int elem = 0;
	do{
	  int prev = now;
	  now = dat[now];
	  dat[prev] = prev;
	  elem++;
	}while(start != now);
	ans += getscore(elem);

#ifdef DEBUG
	cerr << " "<< i << " " << elem << " " << ans << endl;
#endif
    }
    cout << "Case #" << case_no+1 << ": " << fixed << setprecision(7) << ans+eps << endl;
  }

  return 0;
}
