#include <stdio.h>
#include <limits.h>
#if 0
#define swap(T,a,b) { T t;t=a;a=b;b=t; }

void 
bblSort ( long long *a, long long cnt )
{
    long long i, j;
    for ( i = 0; i < cnt; i++ )
        for ( j = i + 1; j < cnt; j++ )
            if ( a[i] > a[j] )
                swap(long long, a[i], a[j]);
}

long long  
minMult( long long *x, long long *y, long long n )
{
    long long i, p1 = 0;
    for ( i = 0; i < n; i++ ) 
        p1 = p1 + x[i] * y [n - i - 1]; 
    
    return p1;
}

long long minMultRec( long long *x, long long *y, long long n )
{
    long long i, j, p;
    long long sol =  ~(((long long)1) << 63);
    
    if ( n == 1 )
        return x[0]*y[0];

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            swap(long long, x[0], x[i]);
            swap(long long, y[0], y[j]);
            p = x[0] * y[0] + minMultRec( x+1, y+1, n-1 );
            swap(long long, x[0], x[i]);
            swap(long long, y[0], y[j]);
            if ( p < sol )
                sol = p;
        }
    }
    return sol;
}

#define MAX_IP 1000
#endif

long long
combs( long long *x, long long *y, long long n )
{
    long long i, j, k, sol = 0;

    for ( i = 0; i < n ; i++ ) {
        for ( j = i+1; j < n; j++ ) {
            if ( j == i )
                continue;
            for ( k = j+1; k < n; k++ ) {
                if ( k == i || k == j )
                    continue;
                if( ( x[i] + x[j] + x[k] ) % 3 == 0 &&
                    ( y[i] + y[j] + y[k] ) % 3 == 0 )
                sol++;
            }
        }
    }
    
    

    return sol;
}

main()
{
    long long x[100000], y[100000];

    long long N, Ni, i, n, A, B, C, D, M, sol;

    scanf("%lld", &N);

    for ( Ni= 0; Ni < N; Ni++ ) {
        scanf("%lld",&n);
        scanf("%lld",&A);
        scanf("%lld",&B);
        scanf("%lld",&C);
        scanf("%lld",&D);
        scanf("%lld",&x[0]);
        scanf("%lld",&y[0]);
        scanf("%lld",&M);
        for ( i = 1; i < n; i++ ) {
            x[i] = (A * x[i-1] + B) % M;
            y[i] = (C * y[i-1] + D) % M;
        }
        
        sol = combs( x, y, n );

        printf("Case #%lld: %lld\n", Ni+1, sol);
    }
}
