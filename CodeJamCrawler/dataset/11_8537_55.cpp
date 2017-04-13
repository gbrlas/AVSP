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

const long double EPS(1.0e-8);

int main(){
  int T; cin >> T;
  REP(case_no, T){
    
    int C;
    long long D;
    cin >> C >> D;
    vector<pair<int,int> > vendors(C);
#define POSITION first
#define VALUE second
    REP(i, C){
      cin >> vendors[i].POSITION >> vendors[i].VALUE;
    }
    long double maxv(1e13), minv(0);
    REP(i, 5000){
      long double midv((maxv + minv) * .5);
      long double leftmost(-1.0 * 1e15);
      bool ok(true);
      FOR_EACH(v, vendors){
	long double left = v->POSITION - midv;
	long double rightmax = v->POSITION + midv;
	if(left < leftmost) left = leftmost;
	long double right = left + (v->VALUE - 1) * D;
	//	fprintf(stderr, " %d %Lf %Lf %Lf\n", v - vendors.begin(), left, rightmax, right);
	if(rightmax < right - EPS){
	  ok = false; //break;
	}
	leftmost = right + D;
      }
      if(ok){
	maxv = midv;
      }else{
	minv = midv;
      }
    }
    
    printf("Case #%d: %.9lf\n", case_no+1, (double)minv);
  }
  return 0;
}
