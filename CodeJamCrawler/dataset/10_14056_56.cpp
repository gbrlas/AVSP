#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int prime[1000100];
int a[100];

typedef long long int64;
int64 exgcd(int64 m,int64 & x,int64 n,int64 & y)  // Extend Euclid 
{   
int64 x1,y1,x0,y0;
    x0=1;y0=0;
    x1=0;y1=1;
    int64 r=(m%n+n)%n;
    int64 q=(m-r)/n;
    x=0;y=1;
    while(r)
    {  
x=x0-q*x1;y=y0-q*y1; x0=x1;y0=y1;
        x1=x;y1=y;
        m=n;n=r;r=m%n;
    q=(m-r)/n;
    }
    return n;
}

main(){
	freopen( "As.in", "r", stdin );
	freopen( "As.out", "w", stdout );
	
	int i, j, n, end, result, P;
	int d, m, t, tt = 0;
	long long A, B, C, D, AA, x, r;
	
	memset ( prime, 0, sizeof ( prime ) );
	for ( i = 2; i < 1000100; i ++ )
		if ( prime[i] == 0 )
			for ( j = 2; i * j < 1000100; j ++ )
				prime[ i * j ] = 1;
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %d", &d, &n );
		for ( i = 0; i < n; i ++ )
			scanf ( "%d", a + i );
		m = a[0];
		for ( i = 1; i < n; i ++ )
			m = max( m, a[i] );
		if ( n == 1 ){
			printf( "Case #%d: I don't know.\n", ++ tt );
			continue;
		}
		if ( n == 2 ){
			if ( a[0] == a[1] )
				printf( "Case #%d: %d\n", ++ tt, a[0] );
			else
				printf( "Case #%d: I don't know.\n", ++ tt );
			continue;
		}
		end = 1;
		while( d -- )
			end *= 10;
		result = -1;
		for ( P = m + 1; P < end; P ++ )
			if ( prime[P] == 0 ){
				B = ( a[1] - a[0] + P ) % P;
				C = P;
				D = ( a[2] - a[1] + P ) % P;
				r = exgcd(B,AA,C,x);
//				cout << P << " " << B << " " << C << " " << D << " " << AA << endl;
				if ( D % r )
					AA = -1;
		        else{
		            long long k=D/r;
		            long long tmp=C/r;
		            AA*=k;
		            AA=(AA%tmp+tmp)%tmp;
		        }
		        A = AA;
		        B = ( ( 1LL * a[1] - 1LL * A * a[0] ) % P + P ) % P;
				for ( i = 2; i < n; i ++ )
					if ( ( 1LL * a[ i - 1 ] * A + B ) % P != a[i] )
						break;
				if ( i == n )
					if ( result == -1 )
						result = ( 1LL * a[ n - 1 ] * A + B ) % P;
					else
						if ( result != ( 1LL * a[ n - 1 ] * A + B ) % P )
							result = -2;
			}
		if ( result == -1 || result == -2 )
			printf( "Case #%d: I don't know.\n", ++ tt );
		else
			printf( "Case #%d: %d\n", ++ tt, result );
	}
	
	return 0;
}
