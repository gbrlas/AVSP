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

set<string> dirs;

double x[50], v[50], t[50];
bool win[50];
double tmeet[50][50];
int needs[50];
VI bestwinners;

int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int n; ifs >> n;

	F(k,0,n) {
		int N,K,B,T; ifs >> N >> K >> B >> T;
		F(j,0,N)
			ifs >> x[j];
		F(j,0,N)
			ifs >> v[j];
		F(j,0,N) {
			t[j] = (B-x[j]) / v[j];
			if( t[j] < T+EPS )
				win[j] = true;
			else
				win[j] = false;
		}
		F(i,0,N) F(j,i+1,N) {
			if( v[i] == v[j] )
				tmeet[i][j] = tmeet[j][i] = 2000000000;
			else
				tmeet[i][j] = tmeet[j][i] = (x[i]-x[j]) / (v[j]-v[i]);
			if( tmeet[i][j] > 0 && v[j]>v[i] && win[j] )
				if( !win[i] && tmeet[i][j] < T )
					++needs[j];
			if( tmeet[i][j] > 0 && v[j]<v[i] && win[i] )
				if( !win[j] && tmeet[i][j] < T )
					++needs[i];
		}
		F(i,0,N)
			if( win[i] )
				bestwinners.push_back( needs[i] );
		sort( bestwinners.begin(), bestwinners.end() );
		if( (int)bestwinners.size() < K )
			ofs << "Case #" << k+1 << ": " << "IMPOSSIBLE" << endl;
		else {
			int ret=0;
			F(i,0,K)		
				ret += bestwinners[i];
			ofs << "Case #" << k+1 << ": " << ret << endl;
		}
		bestwinners.clear();
		memset( tmeet,0,sizeof(tmeet) );
		memset( needs,0,sizeof(needs) );
	}	// next case
	return 0;
}

