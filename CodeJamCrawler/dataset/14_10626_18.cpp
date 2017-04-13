#include <iostream>
#include <algorithm>

using namespace std;

int do_case() {
	string in;
	cin >> in;

	size_t index = in.find( '/' );
	long long Q = stoll( in.substr(0,index) );
	long long P = stoll( in.substr(index+1) );

	long long divisor = __gcd( Q, P );
	Q /= divisor;
	P /= divisor;

	int tmp = 1;
	bool found = false;
	for( int i=1; i<=40; ++i ) {
		if( P == tmp ) { found=true; break; }
		tmp *= 2;
	}
	if( ! found ) return -1;

	int counter = 0;

	while( Q < 2*P ) {
		Q *= 2;

		++counter;
	}

	return counter-1;
}

int main() {
	int cases;
	cin >> cases;

	for( size_t i=0; i<cases; ++i ) {
		int c = do_case();
		if( c < 0 ) {
			cout << "Case #" << (i+1) << ": " << "impossible" << endl;;
		} else {
			cout << "Case #" << (i+1) << ": " << c << endl;;
		}
	}
}
