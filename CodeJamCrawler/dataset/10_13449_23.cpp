#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream in;
	if ( argc >=1 )
		in.open(argv[1]);
	else
		in.open("A-small.in");

	if (!in) {
		cout << "file open failed";
		exit(1);
	}
	
	int problems = 0;

	in >> problems;

	// 0=>empty 1=>R 2=>B
	int nn[50][50] = {0};
	int nnr[50][50] = {0};
	int n = 0;
	int k = 0;
	int j, i;
	for ( int p = 1; p <= problems; p++ ) {
		in >> n;
		in >> k;
		char tmp;
		for ( i = 0; i < n; i++ ) {
			for ( j = 0; j < n; j++ ) {
				in >> tmp;
				if ( tmp == '.' )
					nn[i][j] = 0;
				else if ( tmp == 'R' )
					nn[i][j] = 1;
				else if ( tmp == 'B' )
					nn[i][j] = 2;
			}			
		}
		
		for ( i = 0; i < n; ++i) {
			for ( j = 0; j < n; ++j) {
				nnr[i][j] = nn[n - j - 1][i];
			}
		}

		int n2[50][50];

		int x = 0, y = 0;
		int nx = 0, ny = 0;
		for ( i = 0; i < n; i++ ) {
			x = 0;
			for ( j = 0; j < n; j++ ) {
				if ( nnr[i][j] != 0 ) {
					x = 1;
					if ( j > nx )
						nx = j;
				}
				n2[ny][j] = nnr[i][j];
			}
			if ( x != 0 ) {
				ny++;
			}
		}
		nx++;

		for ( j = 0; j < nx; j++ ) {
			for ( i = ny - 1; i > 0; i-- ) {
				if ( n2[i][j] == 0 ) {
					for ( int ii = i-1; ii >= 0; ii-- ) {
						if ( n2[ii][j] > 0 ) {
							n2[i][j] = n2[ii][j];
							n2[ii][j] = 0;
//							i = ii;
							break;
						}
					}
				}
			}
		}
		/*for ( i = 0; i < ny; i++ ) {
			for ( j = 0; j < nx; j++ ) {
				cout << n2[i][j];
			}
			cout << endl;
		}*/
		int cc[3];
		cc[2] = cc[1] = 0;
		int c = 0;
		int jj, ii;
		for ( i = ny - 1; i >= 0; i-- ) {
			for ( j = 0; j < nx; j++ ) {
				int count = 1;
				c = n2[i][j];
				if ( c == 0 ) break;
				if ( cc[c] == 1 ) continue;

				if ( nx - j >= k ) {
					for ( int jj = j + 1; jj < nx; jj++ ) {
						if ( n2[i][jj] == c ) {
							count++;
						} else
							break;
					}
					if ( count >= k ) {
						cc[c] = 1;
						continue;
					}
				}
				count = 1;
				for ( int ii = i - 1; ii >= 0; ii-- ) {
					if ( n2[ii][j] != c )
						break;
					else
						count++;
				}
				if ( count >= k ) {
					cc[c] = 1;
					continue;
				}
				count = 1;
				jj = j;
				for ( int ii = i - 1; ii >= 0; ii-- ) {
					jj--;
					if ( jj < 0 || n2[ii][jj] != c )
						break;
					else
						count++;
				}
				if ( count >= k ) {
					cc[c] = 1;
					continue;
				}
				count = 1;
				jj = j;
				for ( int ii = i - 1; ii >= 0; ii-- ) {
					jj++;
					if ( jj >= nx || n2[ii][jj] != c )
						break;
					else
						count++;
				}
				if ( count >= k ) {
					cc[c] = 1;
					continue;
				}
			}
		}

		char result = 'N';

		cout << "Case #" << p << ": ";

		if ( cc[2] == 1 && cc[1] == 1 )
			cout << "Both";
		else if ( cc[2] == 1 && cc[1] == 0 )
			cout << "Blue";
		else if ( cc[2] == 0 && cc[1] == 1 )
			cout << "Red";
		else if ( cc[2] == 0 && cc[1] == 0 )
			cout << "Neither";

		cout << endl;


		//printf("Case #%d: ", i);
	}
}
