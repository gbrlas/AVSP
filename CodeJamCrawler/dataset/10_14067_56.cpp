#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct Min{
	int need, left;
	friend bool operator < ( const Min &a, const Min &b ){
		return a.need > b.need;
	}
	Min(){}
	Min( int n, int l ){ need = n;	left = l; }
} now;

priority_queue< Min > heap;
int vst[100100];
int dp[100100];
int a[110];

main(){
	int t, tt = 0;
	long long L;
	int N, basic, m, i, j;
	int n, sub, next, nextneed;
	
	freopen( "Bl.in", "r", stdin );
	freopen( "Bl.out", "w", stdout );
	
	scanf ( "%d", &t );
	while( t -- ){
		cin >> L >> n;
		for ( i = 0; i < n; i ++ )
			scanf ( "%d", a + i );
		m = a[0];
		for ( i = 1; i < n; i ++ )
			m = max( m, a[i] );
		if ( L % m == 0 ){
			cout << "Case #" << ++ tt << ": " << L / m << endl;
			continue;
		}
		basic = 100000000;
		N = m;
		memset ( dp, -1, sizeof ( dp ) );
		dp[0] = 0;
		for ( i = 0; i < n; i ++ ){
			sub = m - a[i];
			while( heap.size() )
				heap.pop();
			memset ( vst, 0, sizeof ( vst ) );
			for ( j = 0; j < N; j ++ )
				if ( dp[j] == -1 )
					heap.push( Min( basic + 1, j ));
				else
					heap.push( Min( dp[j], j ) );
//			cout << sub << endl;
			while( heap.size() ){
				now  = heap.top();
				heap.pop();
				if ( vst[ now.left ] )
					continue;
//				cout << now.left << " " << now.need << endl;
				vst[ now.left ] = 1;
				if ( now.need > basic )
					continue;
				next = ( now.left + sub ) % N;
				if ( now.left + sub >= N )
					nextneed = now.need + 1;
				else
					nextneed = now.need;
				if ( dp[ next ] > nextneed || dp[ next ] == -1 ){
					dp[ next ] = nextneed;
					heap.push( Min( dp[next], next ) );
				}
			}
		}
		if ( dp[ m - L % m ] == -1 )
			cout << "Case #" << ++ tt << ": IMPOSSIBLE" << endl;
		else
			cout << "Case #" << ++ tt << ": " << L / m + 1 + dp[ m - L % m ] << endl;
	}
	
	return 0;
}
