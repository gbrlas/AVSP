#pragma warning( disable : 4786 )

#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <ctype.h>
#include <deque>
#include <queue>
#include <iostream>
#include <stack>
#include <fstream>
#include <ios>

using namespace std;

#define VS vector<string>
#define VI vector<int>
#define VD vector<double>
#define F(v,s,e) for( int v = (s); v < (e); ++v )
#define FA(v,c) for( int v = 0; v < (int)c.size(); ++v )
#define ALL(c) c.begin(), c.end()
#define ISS istringstream
#define OSS ostringstream

#define int64 __int64
const double EPS = 1.E-9;
const double PI = 4*atan(1.);
#define max _MAX
#define min _MIN

const int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const int64 oo=(int64)1000000000*(int64)1000000000;
const int64 MOD = 2000000007;

int ones( int n ) { return n ? 1 + ones(n & (n - 1)) : 0; }  // returns number of set bits
int lsb( int n ) { return (n^(n-1)) & n; }  // return number with only lsb left as set bit

bool overlap( int a1, int a2, int b1, int b2 ) { return a2>=b1 && a1<=b2; }

template<class T> inline T sqr( T x ) { return x*x; }

int exp( int x, int p ) {
  if( p == 0 ) return 1;
  int r = exp( x, p/2 );
  return r * r * ( p&0x1 ? x : 1 );
}

void ASSERT( bool cond ) {
  if( !cond )
    exit(0);
}

struct TRIP {
  int dep, arr;
  bool ba;
};
bool operator<( const TRIP &l, const TRIP &r ) {
  return l.dep < r.dep;
}

vector<TRIP> trips;

int t_a[3661], t_b[3661];

void main() {
ifstream ifs("in.txt");
ofstream ofs("out.txt");
int nc=0; ifs >> nc;
F(ic,0,nc) {
  memset(t_a,0,sizeof(t_a)); memset(t_b,0,sizeof(t_b));
  trips.clear();
  int turn=0; ifs >> turn; 
  int na=0, nb=0; ifs >> na >> nb;
  F(ia,0,na) {
    int dh=0,dm=0,ah=0,am=0; char dummy;
    ifs >> dh >> dummy >> dm >> ah >> dummy >> am;
    TRIP t = { dh*60+dm, ah*60+am, false };
    trips.push_back( t );
  }
  F(ib,0,nb) {
    int dh=0,dm=0,ah=0,am=0; char dummy;
    ifs >> dh >> dummy >> dm >> ah >> dummy >> am;
    TRIP t = { dh*60+dm, ah*60+am, true };
    trips.push_back( t );
  }
  sort( trips.begin(), trips.end() );

  if( trips.empty() ) {
    ofs << "Case #" << ic+1 << ": " << 0 << " " << 0 << endl;
    continue;
  }

  // LOS geht's
  int tota=0, totb=0;//lasttime = trips[0].dep;
  F(i,0,trips.size()) {
    TRIP t = trips[i];
    if( t.ba ) {  // b->a
      // TODO: t_b[t.dep] muss stimmen
      F(j,0,t.dep) {
        if( t_b[j] ) { t_b[t.dep] += t_b[j]; t_b[j] = 0; }
      }
      if( t_b[t.dep] == 0 ) { ++t_b[t.dep]; ++totb; }
      --t_b[t.dep];
      ++t_a[t.arr+turn];
    }
    else  { // a->b
      F(j,0,t.dep) {
        if( t_a[j] ) { t_a[t.dep] += t_a[j]; t_a[j] = 0; }
      }
      if( t_a[t.dep] == 0 ) { ++t_a[t.dep]; ++tota; }
      --t_a[t.dep];
      ++t_b[t.arr+turn];
    }
    //lasttime = t.dep;
  } // next trip

  ofs << "Case #" << ic+1 << ": " << tota << " " << totb << endl;
} // next case
}