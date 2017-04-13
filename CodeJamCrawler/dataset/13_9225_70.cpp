#include <iostream>
#include <algorithm>

using namespace std;

string solve();

int main() {
	int num_cases;
	cin >> num_cases;

	for( int case_num=0; case_num<num_cases; ++case_num ) {
		cout << "Case #" << (case_num+1) << ": " << solve() << endl;
	}

	return 0;
}

string solve() {
	int n, m;
	cin >> n >> m;

	int lawn[n][m];
	for( int i=0; i<n; ++i ) {
		for( int j=0; j<m; ++j ) {
			cin >> lawn[i][j];
		}
	}

	int highHor[n];
	for( int i=0; i<n; ++i ) {
		highHor[i] = 0;
		for( int j=0; j<m; ++j ) {
			highHor[i] = max(lawn[i][j],highHor[i]);
		}
	}

	int highVer[m];
	for( int j=0; j<m; ++j ) {
		highVer[j] = 0;
		for( int i=0; i<n; ++i ) {
			highVer[j] = max(lawn[i][j],highVer[j]);
		}
	}

	for( int i=0; i<n; ++i ) {
		for( int j=0; j<m; ++j ) {
			if( lawn[i][j] != highHor[i] && lawn[i][j] != highVer[j] )
				return "NO";
		}
	}

	return "YES";
}
