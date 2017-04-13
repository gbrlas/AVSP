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

string w[5000], m[500];

int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int n,d,l; ifs >> l >> d >> n;
	F(i,0,d)
		ifs >> w[i];
	F(i,0,n)
		ifs >> m[i];
	
	F(i,0,n) {
		int p=0;	// read position in token
		set<char> s[15];
		F(j,0,l) {
			if( m[i][p++] == '(' ) {	// multiple poss. characters
				while( m[i][p++] != ')' )
					s[j].insert( m[i][p-1] );
			}
			else {	// sure known character
				s[j].insert( m[i][p-1] );
			}
		}	// next token l[j] of message m[i]
		int ret=0;	// number of word-matches for this message
		F(jj,0,d) {	// iterate all words of language
			bool poss = true;
			F(k,0,l)
				if( s[k].find( w[jj][k] ) == s[k].end() ) {
					poss = false; 
					break;
				}
			if( poss )
				++ret;
		}	// next word
		
		ofs << "Case #" << i+1 << ": " << ret << endl;
	}	// next message m[i]
	return 0;
}

