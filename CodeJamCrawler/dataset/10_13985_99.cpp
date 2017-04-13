#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[1100];
int next[1100];
int record[1100];

main(){
	freopen( "Cl.in", "r", stdin );
	freopen( "Cl.out", "w", stdout );
	
	long long result;
	int start, ptr, cnt;
	int i, n, R, k, t, tt = 0;
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d %d", &R, &k, &n );
		for ( i = 0; i < n; i ++ )
			scanf ( "%d", a + i );
		memset ( record, 0, sizeof ( record ) );
		ptr = 0;
		start = 0;
		result = 0;
		while( R -- ){
			if ( record[start] != 0 ){
				result += record[start];
				start = next[start];
				ptr = start;
				continue;
			}
			cnt = 0;
			for ( i = 0; i < n; i ++ ){
				cnt += a[ ptr ++ ];
				if ( ptr == n )
					ptr = 0;
				if ( cnt + a[ptr] > k )
					break;
			}
			record[start] = cnt;
			next[start] = ptr;
			result += cnt;
			start = ptr;
		}
		cout << "Case #" << ++ tt << ": " << result << endl;
	}
	
	return 0;
}
