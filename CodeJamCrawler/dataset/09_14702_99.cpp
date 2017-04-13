#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>
#include <map>
#include <set>

using namespace std;

const char* str = "welcome to code jam";
const int LN = strlen(str);
const int MOD = 10000;

char buf[1000];
int X[1000], Y[1000];

int main()
{
  freopen( "C-small-attempt0.in", "rt", stdin );
  freopen( "c.out", "wt", stdout );

  int N;
  
  scanf( "%d\n", &N );
  for ( int Case = 0; Case < N; ++Case )
  {
    fgets( buf, sizeof(buf), stdin );
    int len = strlen( buf ) - 1;
    buf[len] = 0;

    int *A = &X[0], *B = &Y[0];

    memset( A, 0, sizeof( X ) );
    for ( int j = 0; j < len; ++j )
    {
      memcpy( B, A, sizeof( X ) );

      for ( int k = LN - 1; k >= 0; --k )
      {
        if ( str[k] == buf[j] )
        {
          if ( k == 0 ) B[k] = (B[k] + 1) % MOD;
          else if ( A[k-1] > 0 ) B[k] = (B[k] + A[k-1] ) % MOD;
        }
      }

      swap(A, B);
    }

    printf( "Case #%d: %04d\n", Case + 1, A[LN-1] );
  }

  return 0;
}
