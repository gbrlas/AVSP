// GCJ2009.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <math.h> 
#include <algorithm> 
#include <string> 
#include <vector> 
#include <map> 
#include <set> 
#include <sstream> 
#include <iostream> 
#include <ctype.h> 
#include <list>
#include <queue>
#include <fstream>
#include <iomanip>

using namespace std; 

#define VS vector<string> 
#define VI vector<int> 
#define VD vector<double>
#define F(v,s,e) for( int v = (int)(s); v < (int)(e); ++v ) 
#define FA(v,c) for( int v = 0; v < (int)c.size(); ++v )
#define SET00(x) memset( (x), 0, sizeof(x));
#define SETFF(x) memset( (x), 0xff, sizeof(x));
#define ALL(c) c.begin(), c.end()

#define ISS istringstream 
#define OSS ostringstream 

#define int64 __int64

const double PI = 4*atan(1.); 
const double EPS = 1.E-12;

int g[1000], hm[1000], ni[1000], v[1000];

int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int n; ifs >> n;

	F(i,0,n) {
		int R,k,N; ifs >> R >> k >> N;	// R trips, k places, N groups
		F(j,0,N) 
			ifs >> g[j];
		F(j,0,N) {
			int hml = 0, nil=j;
			while( hml+g[nil] <= k ) {
				hml += g[nil];
				if( ++nil == N )
					nil = 0;
				if( nil == j )	// can't take more than all people in one ride
					break;
			}
			hm[j] = hml;
			ni[j] = nil;
			v[j] = 0;
		}

		int64 earn = 0;
		int idx = 0, cl = 0;
		bool once = true;
		F(ri,0,R) {
			earn += hm[idx];
			v[idx] = true;
			idx = ni[idx];
			++cl;
			/*if( v[idx] && once ) {
				ri = R-(R%cl)-1;
				earn *= (R/cl);
				once = false;
			}*/
		}
		
		ofs << "Case #" << i+1 << ": " << earn << endl;
	
	}	// next case
	return 0;
}

