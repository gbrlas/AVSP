#include <iostream>
using namespace std;

char word[5500][20];
char readin[100000];

main(){
	int L, n, m, tt = 0;
	int i, j, k, flag;
	int record[20];
	int cnt;
	
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	
	scanf ( "%d %d %d", &L, &n, &m );
	
	for ( i = 0; i < n; i ++ )
		scanf ( "%s", word[i] );
	for ( i = 0; i < m; i ++ ){
		scanf ( "%s", readin );
		for( k = 0; k < L; k ++ )
			record[k] = 0;
		k = 0;
		flag = 0;
		for( j = 0; readin[j]; j ++ ){
			if ( readin[j] == '(' )
				flag = 1;
			if ( readin[j] == ')' )
				flag = 0;
			if ( readin[j] <= 'z' && readin[j] >= 'a' )
				record[k] |= ( 1 << ( readin[j] - 'a' ) );
			if ( flag == 0 )
				k ++;
		}
		cnt = 0;
		for ( j = 0; j < n; j ++ ){
			for ( k = 0; k < L; k ++ )
				if ( ( ( 1 << ( word[j][k] - 'a' ) ) & ( record[k] ) ) == 0 )
					break;
			if ( k == L )
				cnt ++;
		}
		printf( "Case #%d: %d\n", ++ tt, cnt );
	}
	
	return 0;
}
