#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) FOR(i,0,n-1)
#define PII pair<int,int>
#define VI vector<int>
#define INF 0x3FFFFFFF

using namespace std;

int main()
{
    int T;
    scanf( "%d", &T );
    REP( ii, T ) {
        int N;//, cnt=0;
        scanf( "%d", &N );
        int *A = new int[N];
        int *B = new int[N];
        REP( i,N ) scanf( "%d%d", &A[i], &B[i] );
        if( N > 1 && (( A[0] < A[1] && B[1] < B[0] ) || ( A[1] < A[0] && B[0] < B[1] )) ) {
            printf( "Case #%d: 1\n", ii+1 );
        }
        else printf( "Case #%d: 0\n", ii+1 );
    }
    return 0;
}
