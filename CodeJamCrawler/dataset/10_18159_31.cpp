#include <iostream>
#include <vector>
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

struct rect_t {
	int r1, c1, r2, c2;
};

vector<rect_t> rects;
int map[2][101][101];

int main() {
	int cases;

	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int n_rects;
		cin >> n_rects;
		int minr = 1<<30;
		int maxr = -100;
		int minc = 1<<30;
		int maxc = -100;

		rects.resize( n_rects );
		for( int i = 0; i < n_rects; ++i ) {
			int r1, c1, r2, c2;
			cin >> c1 >> r1 >> c2 >> r2;
			minr = min( minr, r1 );
			minr = min( minr, r2 );
			maxr = max( maxr, r1 );
			maxr = max( maxr, r2 );
			minc = min( minc, c1 );
			minc = min( minc, c2 );
			maxc = max( maxc, c1 );
			maxc = max( maxc, c2 );
			rects[i] = (rect_t) { r1, c1, r2, c2 };
		}

		memset( map, 0, sizeof(map) );
		for( int i = 0; i < n_rects; ++i ) {
			for( int r = rects[i].r1; r <= rects[i].r2; ++r ) {
				for( int c = rects[i].c1; c <= rects[i].c2; ++c ) {
					map[0][r][c] = 1;
				}
			}
		}

		int from = 0;
		int to = 1;
		int found;
		int cnt = -1;
		do {
			++cnt;
			found = 0;
			for( int r = minr; r <= maxr; ++r ) {
				for( int c = minc; c <= maxc; ++c ) {
					int delta = 0;
					if( map[from][r][c] ) {
						found = 1;
						if( (r == 0 || !map[from][r-1][c]) && (c == 0 || !map[from][r][c-1] ) ) {
							delta = -1;
						}
					} else {
						if( r >= 1 && map[from][r-1][c] && c >= 1 && map[from][r][c-1] ) {
							delta = 1;
						}
					}
					if( delta == 0 ) {
						map[to][r][c] = map[from][r][c];
					} else if( delta == 1 ) {
						map[to][r][c] = 1;
					} else {
						// delta = -1
						map[to][r][c] = 0;
					}
				}
			}
			swap( from, to );
		} while( found );

		cout << "Case #" << caseid << ": " << cnt << endl;
	}
	return 0;
}
