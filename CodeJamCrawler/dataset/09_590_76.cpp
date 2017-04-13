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

int a[100][100];
char s[100][100];
int w,h;
char label;

char go( int x, int y ) {
if( s[y][x] )
	return s[y][x];
int mina=a[y][x], nx=x, ny=y;
if( y>0 && a[y-1][x]<mina ) {
	mina = a[y-1][x];
	nx=x; ny=y-1;
}
if( x>0 && a[y][x-1]<mina ) {
	mina = a[y][x-1];
	nx=x-1; ny=y;
}
if( x<w-1 && a[y][x+1]<mina ) {
	mina = a[y][x+1];
	nx=x+1; ny=y;
}
if( y<h-1 && a[y+1][x]<mina ) {
	mina = a[y+1][x];
	nx=x; ny=y+1;
}
if( ny==y && nx==x )	// found a new sink
	return s[y][x] = label++;
s[y][x] = go( nx, ny );
};

int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int t; ifs >> t;
	
	F(i,0,t) {
		ifs >> h >> w;
		label = 'a';
		F(y,0,h) F(x,0,w) {
			ifs >> a[y][x];
			s[y][x] = 0;
		}

		F(y,0,h) F(x,0,w)
			go(x,y);

		ofs << "Case #" << i+1 << ":" << endl;
		F(y,0,h) F(x,0,w) {
			ofs << s[y][x];
			if( x==w-1 )
				ofs << endl;
			else 
				ofs << ' ';
		}
	}	// next case
	return 0;
}

