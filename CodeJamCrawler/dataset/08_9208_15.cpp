#include <stdio.h>
#include <limits.h>

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

main()
{
    long long T, t, n, i, p, x[MAX_IP], y[MAX_IP];

    scanf("%lld", &T);
    for ( t = 0; t < T; t++ ) {
        scanf("%lld", &n);
        /* X */
        for ( i = 0; i < n; i++ ) {
            scanf("%lld", &x[i]);
        }
        /* Y */
        for ( i = 0; i < n; i++ ) {
            scanf("%lld", &y[i]);
        }
#if 1
        bblSort(x, n);
        bblSort(y, n);

#if 0
         /* X */
        printf("\n");
        for ( i = 0; i < n; i++ ) {
            printf("%lld ", x[i]);
        }
        /* Y */
        printf("\n");
        for ( i = 0; i < n; i++ ) {
            printf("%lld ", y[i]);
        }
        printf("\n");
#endif
        p = minMult(x,y,n);
#else
        p = minMultRec(x,y,n);
#endif

        printf("Case #%lld: %lld\n", t+1, p);
    }
}
