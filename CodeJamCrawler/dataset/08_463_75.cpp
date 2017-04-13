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

const double PART = 1000.;
int nsq[2002];

void main() {
ifstream ifs("in.txt");
ofstream ofs("out.txt");
ofs.setf(ios::fixed);
ofs.precision(6);

int nc=0; ifs >> nc;
F(ic,0,nc) {
  double f, R, t, r, g;
  ifs >> f >> R >> t >> r >> g;
  if( g < 2*f ) { // fly can't even escape through full square
    ofs << "Case #" << ic+1 << ": " << 1.0 << endl;
    continue;    
  }
  double Ri = R - t - f;
  int nfs = (Ri+r) / (2*r+g); // max. full squares in positive direction
  
  double afs = (g-2*f) * (g-2*f);
  double aesc = 0.;   // total area, where fly escapes

  F(ix,0,nfs+2) F(iy,0,nfs+2) {
    double xs = (2*ix+1)*r + (ix)*g + f;  // squares of pot. esc. locs
    double ys = (2*iy+1)*r + (iy)*g + f;
    double xe = xs+g-2*f, ye = ys+g-2*f;
    if( xs*xs + ys*ys > Ri*Ri )
      continue; // square outside Ri
    if( xe*xe + ye*ye < Ri*Ri ) {
      aesc += afs;  // square fully contained in Ri
      continue;
    }
    // partial square
    double sp = (g-2*f)/PART;
    double ap = 0.; // area of this partial square
    double xmax = sqrt(Ri*Ri-ys*ys);
    bool done=false;
    F(j,0,PART) {
      double x1 = xs + j*sp;
      double x2 = x1+sp;
      if( x2 > xmax ) {
        x2 = xmax;
        done=true;
      }
      double y1 = sqrt( Ri*Ri - x1*x1 );
      double y2 = sqrt( Ri*Ri - x2*x2 );
      y1 -= ys; y2 -= ys;
      y1 = min(y1,g-2*f); y2=min(y2,g-2*f);
      double da = (x2-x1)*(y1+y2)/2.;
      if( da > 0 )
        ap += da;
      if( done )
        break;
    }
    aesc += ap;
  }

  /*F(x,1,nfs+1) {
    double rx = sqrt( Ri*Ri - sqr((2*x-1)*r+x*g) );
    nsq[x] = (rx+r) / (2*r+g);
    aesc += nsq[x] * afs;
  }*/
  aesc *= 4;
  
/*  double atp=0.;  // total area of partial squares
  //double ys = (2*nfs+1)*r + nfs*g + f;  // ys of partial squares
  F(i,1,nfs+2) {
    double ys = (2*nsq[i]+1)*r + nsq[i]*g + f;  // ys of partial squares
    double xs = (2*i-1)*r + (i-1)*g + f;
    double sp = (g-2*f)/1000.;
    double ap = 0.; // area of this partial square
    F(j,0,1000) {
      double x1 = xs + j*sp;
      double x2 = x1+sp;
      double y1 = sqrt( (Ri-f)*(Ri-f) - x1*x1 );
      double y2 = sqrt( (Ri-f)*(Ri-f) - x2*x2 );
      y1 -= ys; y2 -= ys;
      double da = sp*(y1+y2)/2.;
      if( da > 0 )
        ap += da;
    }
    atp += ap;
  }
  aesc += 4*atp;  // four sides of racket
  //aesc += PI* (R*R - Ri*Ri);  // ring of racket
  */
  double phit = 1. - aesc/(PI*R*R);

  ofs << "Case #" << ic+1 << ": " << phit << endl;
} // next case
}