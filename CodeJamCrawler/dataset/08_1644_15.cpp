#include <iostream>

using namespace std;

#define REPEAT(i,n) for( int i(0), _##n(n); i < _##n; ++i )

template <typename TYPE>
TYPE* newArray( int noof )
    {
    TYPE* res = (TYPE*)malloc( sizeof(TYPE) * noof );
    memset( res, 0, sizeof(TYPE) * noof );
    return res;
    }

#ifdef DEBUG
#define D fprintf
#else
#define D debug
inline void debug( ... ) {}
#endif

static char buff[1000];

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    freopen( "error.txt", "w", stderr );

    int noofCases = atoi( gets( buff ) );

    REPEAT( c, noofCases )
        {
        int deckSize = atoi( gets( buff ) );

        D( stderr, "Case %d, Size %d\n", c, deckSize );

        int* deck = newArray<int>( deckSize );

        int done = 0;
        int pos = 0;

        while( done != deckSize )
            {
            if( deck[pos] == 0 )
                {
                deck[pos] = ++done;
                if( done == deckSize ) break;

                pos++; if( pos == deckSize ) pos = 0;

                for( int step = 0; step < (done); step++ )
                    {
                    while( deck[pos] != 0 )
                        {
                        pos++; if( pos == deckSize ) pos = 0;
                        }
                    pos++; if( pos == deckSize ) pos = 0;
                    }
                }

            while( deck[pos] != 0 )
                {
                pos++; if( pos== deckSize ) pos = 0;
                }
            }

        //REPEAT( d, deckSize )
            //{
            //D( stderr, " %d", deck[d] );
           // }
        //D( stderr, "\n" );

        int noofIndexes;
        scanf( "%d", &noofIndexes );

        printf( "Case #%d:", c+1 );
        REPEAT( i, noofIndexes )
            {
            int index;
            scanf( "%d", &index );
            printf( " %d", deck[ index-1 ] );
            }
        scanf( "\n" );
        printf( "\n" );
        }

    return 0;
}
