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

const char r[] = "welcome to code jam";
char s[500];

int go( int ps, int pr ) {
if( pr == strlen(r) )
	return 1;
int c=0;
F(i,ps,strlen(s)) 
	if( s[i] == r[pr] ) {
		c = ( c + go(i+1,pr+1) ) % 10000;
	}

return c;
}

int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int t; ifs >> t;
	char dummy[5]; ifs.getline( dummy, 5 );	// read LF and ignore
	
	F(i,0,t) {
		ifs.getline( s, 502 );
		int c = go(0,0);
		ofs << "Case #" << i+1 << ": " << setw(4) << setfill('0') << c << endl;
	}	// next case
	return 0;
}

