#include <iostream>

using namespace std;

#define REPEAT(i,n) for( int i(0), _##n(n); i < _##n; ++i )

 int compare_ints( const void* a, const void* b ) {
   int* arg1 = (int*) a;
   int* arg2 = (int*) b;
   if( *arg1 < *arg2 ) return -1;
   else if( *arg1 == *arg2 ) return 0;
   else return 1;
 }

#ifdef DEBUG
#define D fprintf
#else
#define D debug
inline void debug( ... ) {}
#endif

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    freopen( "error.txt", "w", stderr );

    char buff[1000];

    int noofCases = atoi( gets( buff ) );

    REPEAT( i, noofCases )
        {
        int noArgs = atoi( gets( buff ) );

        D( stderr, "%d\n", noArgs );

        int*a = (int*)malloc( sizeof(int)*noArgs );
        int*b = (int*)malloc( sizeof(int)*noArgs );

        REPEAT( ia, noArgs )
            {
            scanf( "%d", &a[ia] );
            }
        REPEAT( ib, noArgs )
            {
            scanf( "%d", &b[ib] );
            }

        gets(buff);

        qsort( a, noArgs, sizeof(int), compare_ints );
        qsort( b, noArgs, sizeof(int), compare_ints );

        int total = 0;
        REPEAT( ic, noArgs )
            {
            D( stderr, "%d\n", total );
            total += a[ic]*b[noArgs-ic-1];
            }

        printf( "Case #%d: %d\n", i+1, total );
        }

    return 0;
}
