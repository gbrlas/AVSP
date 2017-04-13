#include<stdio.h>
#include<iostream>

using namespace std;

const int maxN = 1000;
const int maxM = 10000;
const int maxL = 1000;

const int bzH = 19;
const int mod = 666013;
const int INF = 1000000;

int T;
int N,M;

char SE[ maxN ][ maxL ];
char auxQ[ maxL ];
int Q[ maxM ];

int hash[ maxN ];
int R[ maxN ][ maxM ];

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);

    scanf("%d\n", &T );

    for (int cN = 1;T;T--, cN++) {

        /* Clean */
        memset( SE, 0, sizeof( SE ) );
        memset( Q, 0, sizeof( Q ) );
        memset( hash, 0 ,sizeof( hash ) );
        memset( R, 0, sizeof( R ) );

        /*Read*/
        scanf("%d\n", &N );
        for ( int i = 0; i < N; i++ ) {
            fgets( SE[ i ], maxL, stdin );
            int L = strlen( SE[i] );
            for ( int j = 0; j < L; j++ ) {
                hash[i] = ( hash[i]*bzH + SE[i][j] ) % mod;
            }
        }
        scanf("%d\n", &M );
        for ( int i = 0; i < M; i++ ) {
            fgets( auxQ, maxL, stdin );
            int L = strlen( auxQ );
            int cHash = 0;
            for ( int j = 0; j < L; j++ ) {
                cHash = ( cHash*bzH + auxQ[j] ) % mod;
            }

            for ( int j = 0; j < N; j++ )
                if ( cHash == hash[j] )
                    Q[i] = j;
        }
        R[0][ Q[0] ] = -1;
        for ( int i = 1; i < M; i++ )
            for ( int j = 0; j < N; j++ )
                if ( Q[i] != j ) {
                    R[i][j] = INF;
                    for ( int l = 0; l < N; l++ )
                        if ( R[i-1][l] != -1 )
                            R[i][j] = min( R[i][j], R[i-1][l] + ( l!=j ) );
                } else R[i][j] = -1;
        int sol = INF;
        for ( int i = 0; i < N; i++ )
            if ( R[M-1][i] != -1 )
                sol = min( sol, R[M-1][ i ] );
        printf("Case #%d: %d\n", cN, sol );
    }


    return 0;
}
