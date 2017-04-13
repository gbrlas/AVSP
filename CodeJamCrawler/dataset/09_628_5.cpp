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

double sqr( double x ) { return x*x; }

double x[40], y[40], r[40];


double dist( int i1, int i2 ) {
	return sqrt( sqr(x[i1]-x[i2]) + sqr(y[i1]-y[i2]) );
}

int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int t; ifs >> t;

	F(i,0,t) {
		int n; ifs >> n;
		double ret=0.;
		F(j,0,n) {
			ifs >> x[j] >> y[j] >> r[j];
		}
		if( n==1 )
			ofs << "Case #" << i+1 << ": " << r[0] << endl;
		else if( n==2 )
			ofs << "Case #" << i+1 << ": " << max(r[0],r[1]) << endl;
		else {
			ret = max( r[0], r[1]+r[2]+dist(1,2) );
			ret = min( ret, max( r[1], r[0]+r[2]+dist(0,2) ) );
			ret = min( ret, max( r[2], r[0]+r[1]+dist(1,0) ) );
			ofs << "Case #" << i+1 << ": " << ret/2. << endl;
		}
	}	// next case
	return 0;
}

