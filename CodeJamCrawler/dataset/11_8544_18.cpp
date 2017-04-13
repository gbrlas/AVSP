#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<set>
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

const long double EPS(1.0e-10);

int main(){
  int T;
  cin >> T;
  REP(case_no, T){
    int X, S, R, N;
    double t;
    cin >> X >> S >> R >> t >> N;
    vector<pair<int, pair<int,int> > > walkways(N);
#define BEGIN second.first
#define END second.second
#define W first
    int totalLength(0);
    REP(i, N){
      cin >> walkways[i].BEGIN >> walkways[i].END >> walkways[i].W;
      totalLength += walkways[i].END - walkways[i].BEGIN;
    }
    sort(ALL(walkways));
    double ans(0);
    double length = X - totalLength;
    double walkSpeed = S;
    double runSpeed = R;
    double maxRunLength = runSpeed * t;
    double runLength = min(maxRunLength, length);

    ans += runLength / runSpeed;
    ans += (length - runLength) / walkSpeed;
    t -= runLength / runSpeed;
    
    REP(i, N){
      length = walkways[i].END - walkways[i].BEGIN;	
      runSpeed = (R + walkways[i].W);
      walkSpeed = (S + walkways[i].W);
      if(t > EPS){
	maxRunLength = runSpeed * t;
	runLength = min(maxRunLength, length);
	ans += runLength / runSpeed;
	ans += (length - runLength) / walkSpeed;
	t -= runLength / runSpeed;
      }else{
	ans +=  length / walkSpeed;
      }
    }
    printf("Case #%d: %.8lf\n", case_no+1, ans);
  }
  return 0;
}
