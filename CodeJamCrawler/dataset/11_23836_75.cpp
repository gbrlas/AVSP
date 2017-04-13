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

string a[200];
double wp[200];
double owp[200];
double oowp[200];
int games[200];
int wins[200];

int main() {
	int cases;
	cin >> cases;
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ":\n";
		int n;
		cin >> n;
		for( int i = 0; i < n; ++i ) {
			cin >> a[i];
		}
		// wp
		for( int i = 0; i < n; ++i ) {
			games[i] = 0;
			wins[i] = 0;
			for( int j = 0; j < n; ++j ) {
				if( a[i][j] == '1' ) {
					++games[i];
					++wins[i];
				} else if( a[i][j] == '0' ) {
					++games[i];
				}
			}
			wp[i] = (double)wins[i] / (double)games[i];
		}
		// owp
		for( int i =0 ; i < n; ++i ) {
			owp[i] = 0.0;
			for( int j = 0; j < n; ++j ) {
				if( a[i][j] != '.' ) {
					// opponent j
					int w = wins[j];
					int g = games[j]-1;
					if( a[j][i] == '1' ) {
						--w;
					} else if( a[j][i] == '0' ) {
						// do nothing
					} else assert( 1 == 2 );
					owp[i] += (double)w/(double)g;
				}
			}
			owp[i] /= (double)games[i];
		}
		// oowp
		for( int i = 0; i < n; ++i ) {
			oowp[i] = 0.0;
			for( int j = 0; j < n; ++j ) {
				if( a[i][j] != '.' ) {
					oowp[i] += owp[j];
				}
			}
			oowp[i] /= (double)games[i];
		}
		for( int i = 0; i < n; ++i ) {
			//RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP
			double rpi = 0.25*wp[i] + 0.5*owp[i] + 0.25* oowp[i];
			printf( "%.20f\n", rpi );
		}
	}
	return 0;
}
