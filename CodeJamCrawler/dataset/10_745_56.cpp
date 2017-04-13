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

int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int n; ifs >> n;

	F(i,0,n) {
		int M,N; ifs >> M >> N;	// R trips, k places, N groups
		F(j,0,M) { 
			string s; ifs >> s;
			int it=1;
			while( (it = s.find('/', it+1)) != string::npos ) {
				string ss = s.substr(0,it);
				dirs.insert(ss);
			}
			dirs.insert(s);
		}
		int ret=0;
		F(j,0,N) {
			string s; ifs >> s;
			int it = s.find('/',1);
			do {
				string ss = s.substr(0,it);
				if( ss.length() && dirs.find(ss) == dirs.end() ) {
					++ret;
					dirs.insert(ss);
				}
			} while( (it = s.find('/',it+1)) != string::npos );
			if( dirs.find(s) == dirs.end() ) {
				++ret;
				dirs.insert(s);
			}
		}
		ofs << "Case #" << i+1 << ": " << ret << endl;
		dirs.clear();
	}	// next case
	return 0;
}

