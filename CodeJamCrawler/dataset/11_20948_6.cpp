#include "stdio.h"

// from http://en.wikipedia.org/wiki/Binary_GCD_algorithm
int gcd(int u, int v){
	if(u == v || u == 0 || v == 0)
		return u|v;
	if(u%2 == 0){ // if u is even
		if(v%2 == 0) // if u and v are even
			return (2*gcd(u/2, v/2));
		else // u is even and v is odd
			return  gcd(u/2, v);
	}
	else if(v%2 == 0) // if u is odd and v is even
		return gcd(u, v/2);
	else{ // both are odd
		if(u>=v)
			return gcd((u-v)/2, v);
		else
			return gcd((v-u)/2, u);
	}
}

int main(int argc, char* argv[])
{
	int TestCases;
	scanf( "%d", &TestCases );

	int MinGames[101];

	MinGames[ 0 ] = 0;

	for ( int i = 1; i < 101; ++i  ) {
		MinGames[ i ] = 100 / gcd( 100, i );
	}

	for ( int Test = 0; Test < TestCases; ++Test )
	{
		int MaxGamesToday, TodayWinPct, OverallWinPct;
		scanf( "%d %d %d", &MaxGamesToday, &TodayWinPct, &OverallWinPct );

		bool Possible = true;

		if ( OverallWinPct == 100 ) {
			Possible = ( TodayWinPct == 100 );
		} else if ( OverallWinPct == 0 ) {
			Possible = ( TodayWinPct == 0 );
		} else {
			Possible = ( MaxGamesToday >= MinGames[ TodayWinPct ] );
		}

		if ( Possible ) {
			printf( "Case #%d: Possible\n", Test + 1 );
		} else {
			printf( "Case #%d: Broken\n", Test + 1 );
		}
	}

	return 0;
}

