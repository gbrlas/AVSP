#include <stdio.h>

char on( int n, int k );

int main( int argc, char** argv ) {
    int T = 0;
    int i;
    scanf( "%d", &T );
    for( i = 1; i <= T; i++ ) {
        int n, k;
        scanf( "%d %d", &n, &k );
        printf( "Case #%d: %s\n", i, on(n,k) ? "ON" : "OFF" );
    }
    return 0;
}

char on( int n, int k ) {
    char ret = (k>0);
    int i;
    for( i = 0; i < n; i++ ) {
        ret &= k&1;
        k>>=1;
    }
    return ret;
}
