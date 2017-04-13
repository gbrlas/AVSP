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


int N;
void main() { 
ifstream ifs("in.txt"); 
ofstream ofs("out.txt"); 
ifs >> N; 
F(i,0,N) { 
  int P,K,L;
  ifs >> P >> K >> L;
  int64 h[1001];
  F(j,0,L)
	  ifs >> h[j];
  sort( h,h+L,greater<int64>() );
  int64 cnt=0, x=0, f=1;
  while( x < L ) {
	  cnt += f*h[x];
      ++x;
	  if( x%K == 0 )
		f += 1;
  }
  ofs << "Case #" << i+1 << ": " << cnt << endl; 
} 
} 





