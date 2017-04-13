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


struct NO {
	double p;
	string feat;
	int pos, neg;	// indices
};


int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int t; ifs >> t;

	F(i,0,t) {
		string res;
		string s; ifs >> s;
		int ss = (int)s.size();
		bool f=false;
		/*for( int j = ss-1; j>1; --j ) {
			if( s[j-1]<s[j] ) {
				f = true;
				swap( s[j], s[j-1] );
				int k=j;
				while( k < ss-1 && s[k]<s[k+1] ) {
					swap(s[k],s[k+1]);
					++k;
				}
				res = s;
				break;
			}	// end if
		}	// next j*/
		if( next_permutation( s.begin(), s.end() ) )
			res = s;
		else {
			sort( s.begin(), s.end() );
			if( s[0] == '0' ) {
				F(j,0,ss)
					if( s[j] > '0' ) {
						swap( s[0] , s[j] );
						break;
					}
			}
			res = s.substr(0,1) + '0' + s.substr(1);
		}
		ofs << "Case #" << i+1 << ": " << res << endl;
	}	// next case
	return 0;
}

