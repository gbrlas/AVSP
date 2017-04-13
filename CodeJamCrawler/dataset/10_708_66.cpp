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


int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int n; ifs >> n;

	F(i,0,n) {
		int N, K; ifs >> N >> K;
		int x = (1<<N) - 1;
		
		ofs << "Case #" << i+1 << ": ";
	
		if( (K&x) == x )
			ofs << "ON" << endl;
		else 
			ofs << "OFF" << endl;

	}	// next case
	return 0;
}

