// google.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

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

struct P {
	int64 x,y;
};
bool operator<( const P &l, const P &r ) {
if( l.x == r.x )
	return l.y < r.y;
return l.x < r.x;
}
set<P> tr;

int64 N,n,M,A,B,C,D; 
vector<int64> tx, ty;

void main() { 
ifstream ifs("in.txt"); 
ofstream ofs("out.txt"); 
ifs >> N; 
F(i,0,N) { 
  tr.clear(); tx.clear(); ty.clear();
  int x0,y0;
  ifs >> n >> A >> B >> C >> D >> x0 >> y0 >> M; 

  int64 X = x0, Y = y0;
  //tx.push_back(X); ty.push_back(Y);
  P p = {X,Y};
  tr.insert(p);
  F(j,1,n) {
	X = (A * X + B) % M;
	Y = (C * Y + D) % M;
    P p = {X,Y};
	tr.insert(p);
  	//tx.push_back(X); ty.push_back(Y);
  }
  for( set<P>::iterator it = tr.begin(); it != tr.end(); ++it ) {
	tx.push_back( it->x ); ty.push_back( it->y );
  }
  int cnt=0;
  F(j,0,tx.size()) F(k,j+1,tx.size()) F(l,k+1,tx.size()) {
	if( (tx[j]+tx[k]+tx[l])%3 == 0 && (ty[j]+ty[k]+ty[l])%3 == 0 )
		++cnt;
  }
  ofs << "Case #" << i+1 << ": " << cnt << endl; 
} 
} 





