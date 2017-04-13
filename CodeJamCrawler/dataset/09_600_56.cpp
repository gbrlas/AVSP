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

char s[100][100];
int nextnode;
NO no[100];


double search( int idx, double p, const set<string>& fs ) {
if( idx == -1 )
	return p;
if( fs.find( no[idx].feat ) == fs.end() )
	return search( no[idx].neg, p * no[idx].p, fs );
else
	return search( no[idx].pos, p * no[idx].p, fs );
}

int parse( int ln ) {
	string ss(s[ln]);
	ISS iss(ss);
	char c; iss >> c;
	if( c == ')' ) {	// ignore closures
		return parse(ln+1);
	}
	iss >> no[nextnode].p;
	string fs; iss >> fs;
	if( fs[0] == ')' ) {	// leaf
		no[nextnode].pos = no[nextnode].neg = -1;
		return ln+1;
	}
	else {
		no[nextnode].feat = fs;
		int oneno = nextnode;
		no[oneno].pos = ++nextnode;
		int x = parse(ln+1);
		no[oneno].neg = ++nextnode;
		int y = parse(x);
		return y;
	}
}

int main(int argc, char* argv[])
{
	ifstream ifs("in.txt");
	ofstream ofs("out.txt");
	int n; ifs >> n;

	F(i,0,n) {
		nextnode=0;
		ofs << "Case #" << i+1 << ":" << endl;
		int l; ifs >> l;
		char dummy[2]; ifs.getline( dummy, 2 );
		F(j,0,l) {
			ifs.getline( s[j], 100 );
		}
		parse(0);
		int na; ifs >> na;
		F(j,0,na) {
			string aname; ifs >> aname;
			int nf; ifs >> nf;
			set<string> feats;
			F(k,0,nf) {
				string f; ifs >> f;
				feats.insert(f);
			}
			ofs << setprecision(8) << search(0,1.0,feats) << endl;
		}

	}	// next case
	return 0;
}

