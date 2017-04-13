#include <iostream>

using namespace std;

int posibilidades( int A, int B, int K );

int main ( void )
{
   int T, A, B, K;
   int i;
   cin >> T;
   for ( i = 0; i < T; i++ )
   {
      cin >> A >> B >> K;
      cout << "Case #" << i+1 << ": " << posibilidades( A, B, K ) << endl;
   }
   return 0;
}

int posibilidades ( int A, int B, int K )
{
   int res( 0 );
   for ( int i = 0; i < A; i++ )
      for ( int j = 0; j < B; j++ )
         if ( (i & j) < K ) res++;
   return res;
}
