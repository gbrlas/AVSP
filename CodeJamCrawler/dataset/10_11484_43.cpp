#include <stdio.h>

int main( int argc, char** argv ) {
    int T;
    int i;
    int R, k, N;
    int g[1000];

    scanf( "%d", &T );
    for( i = 1; i <= T; i++ ) {
        scanf( "%d %d %d", &R, &k, &N );
        int j;
        for( j = 0; j < N; j++ ) {
            scanf( "%d", &g[j] );
        }
        printf( "Case #%d: %d\n", i, coaster( R, k, N, g ) );
    }
}

int coaster( int R, int k, int N, int* groups ) {
    int r = R;
    int income = 0;
    int g = 0;
    int seats = k;
    int firstg = 0;
    while( r ) {
        if( groups[g] <= seats ) {
            income += groups[g];
            seats -= groups[g];
            g++;
            if( g == N ) g = 0;
            if( g == firstg ) {
                r--;
                seats = k;
            }
        } else {
            r--;
            seats = k;
            firstg = g;
        }
    }
    return income;
}
