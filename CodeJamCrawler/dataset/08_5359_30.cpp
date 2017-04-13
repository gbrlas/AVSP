#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<complex>
#include<list>
#include<deque>
#include<bitset>

#include<algorithm>
#include<functional>
#include<numeric>
#include<iomanip>
#include<utility>
#include<iterator>

#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long int l_int;
const int IMAX((1<<30)-1);
const int LLMAX(1LL<<60);
const double EPS(1.0e-10);
const double mpi(acos(-1.0));


#define FOR(i,a,n) for(int i = (int)(a); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define FOR_EACH(i,v) for(__typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(), (v).end()
#define PB push_back
#define MP make_pair

int main(){
  int N;
  cin >> N;
  REP(case_no, N){
    int ans(0);
    vector<pair<l_int,l_int> > trees;
    l_int n,A,B,C,D,x0,y0,M;
    cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
    l_int X(x0), Y(y0);
    REP(i,n){
      trees.PB(MP(X,Y));
      X = (A*X+B)%M;
      Y = (C*Y+D)%M;      
    }
    sort(ALL(trees));
    trees.erase(unique(ALL(trees)), trees.end());
    REP(i,trees.size()){
      FOR(j,i+1, trees.size()){
	FOR(k,j+1, trees.size()){
	  l_int xp(trees[i].first+trees[j].first+trees[k].first);
	  l_int yp(trees[i].second+trees[j].second+trees[k].second);
	  if(xp%3 == 0 && yp%3 == 0) ans++;
	}
      }
    }
    cout << "Case #" << case_no+1 << ": " << ans << endl;
  }
  return 0;
}
