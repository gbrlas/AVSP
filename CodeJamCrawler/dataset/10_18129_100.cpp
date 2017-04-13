#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

using namespace std;

struct dir_t {
	vector<pair<string,dir_t*> > subdirs;
	dir_t() {
		subdirs.clear();
	}
	~dir_t() {
		for( int i = 0; i < (int)subdirs.size(); ++i ) {
			if( subdirs[i].second )
				delete subdirs[i].second;
		}
	}
};

vector<string> split( string& s ) {
	for( int i = 0; i < (int)s.size(); ++i ) {
		if( s[i] == '/' ) s[i] = ' ';
	}

	istringstream str( s );
	vector<string> res;

	while( str >> s ) {
		res.push_back( s );
	}
	return res;
}

int create_dir( dir_t* pdir, const vector<string>& v, int index ) {
	assert( pdir );
	if( index >= (int)v.size() ) return 0;

	for( int i = 0; i < (int)pdir->subdirs.size(); ++i ) {
		if( pdir->subdirs[i].first == v[index] ) {
			return create_dir( pdir->subdirs[i].second, v, index+1 );
		}
	}
	dir_t* newdir = new dir_t;
	pdir->subdirs.push_back( pair<string,dir_t*>( v[index], newdir ) );
	return 1 + create_dir( newdir, v, index+1 );
}

int main() {
	int cases;
	vector<string> v;

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int n, m;
		dir_t root;

		cin >> n >> m;
		for( int i = 0; i < n; ++i ) {
			string s;
			cin >> s;
			v = split( s );
			create_dir( &root, v, 0 );
		}
		int res = 0;
		for( int i = 0; i < m; ++i ) {
			string s;
			cin >> s;
			v = split( s );
			res += create_dir( &root, v, 0 );
		}
		cout << "Case #" << caseid << ": " << res << endl;
	}
	return 0;
}
