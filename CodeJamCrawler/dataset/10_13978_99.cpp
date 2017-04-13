#include <iostream>
#include <cstdio>
using namespace std;

int a[1100];

main(){
	freopen( "Cs.in", "r", stdin );
	freopen( "Cs.out", "w", stdout );
	
	long long result;
	int cnt, ptr, i, n, R, k, t, tt = 0;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d %d", &R, &k, &n );
		for ( i = 0; i < n; i ++ )
			scanf ( "%d", a + i );
		ptr = 0;
		result = 0;
		while( R -- ){
			cnt = 0;
			for ( i = 0; i < n; i ++ ){
				cnt += a[ ptr ++ ];
				if ( ptr == n )
					ptr = 0;
				if ( cnt + a[ptr] > k )
					break;
			}
			result += cnt;
		}
		cout << "Case #" << ++ tt << ": " << result << endl;
	}
	
	return 0;
}
