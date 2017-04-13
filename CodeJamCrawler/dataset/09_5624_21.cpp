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

inline static double Square(double x){ return x*x; }

struct point{
  double x, y, r;
  point(double x=0., double y=0., double r=0.):x(x), y(y), r(r){}
  friend istream& operator>>(istream& is, point& p){
    return is >> p.x >> p.y >> p.r;
  }
  double dist(const point& p)const{
    return sqrt(Square(x - p.x) + Square(y - p.y));
  }
};

int main(){
  int C, N;
  cin >> C;
  REP(case_no, C){
    double ans(1e100);
    cin >> N;
    vector<point> p(N);
    REP(i, N) cin >> p[i];
    if(N == 1) ans = p[0].r;
    else if(N == 2) ans = max(p[0].r, p[1].r);
    else if(N == 3){
      double maxR = max(p[0].r, max(p[1].r, p[2].r));
      REP(i, 3){
	FOR(j, i+1, 3){
	  double tmp = max((p[i].r + p[j].r + p[i].dist(p[j])) / 2, maxR);
	  ans = min(ans, tmp);
	}
      }
    }else{
      //not implementation error!
      ans = -1;
    }
    printf("Case #%d: %.6lf\n", case_no+1, ans);
  }
  return 0;
}
