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
		in.open("C-small.in");

	if (!in) {
		cout << "file open failed";
		exit(1);
	}
	
	int problems = 0;

	in >> problems;

	long long int n, k, r, j, z, x, v, s;
	long long int out = 0;
	int full = 0;

	for ( int i = 1; i <= problems; i++ ) {
		out = 0;
		in >> r;
		in >> k;
		in >> n;


		// printf("%lld\n",k);

		s = 1;

		long long int groups[n+1];
		for ( j = 1; j <= n; j++ ) {
			in >> groups[j];
		}
		
		for ( z = 1; z <= r; z++ ) {
			full = 0;
			x = k;

			for ( v = s; v <= n; v++ ) {
				// printf("space %lld, current %lld\n", x, groups[v]);

				if ( groups[v] <= x )
					x-=groups[v];
				else {
					full=1;
					s=v;
					break;
				}
			}
			if ( full==0 ) {
				for ( v = 1; v < s; v++ ) {
				// printf("%lld %lld\n", x, groups[v]);
					if ( groups[v] <= x )
						x-=groups[v];
					else {
						full=1;
						s=v;
						break;
					}
				}
			}
			v = k - x;
			// printf("%lld %lld %lld\n",k,x,v);

			out += k-x;
		}

		printf("Case #%d: %lld\n", i, out);
	}
}
