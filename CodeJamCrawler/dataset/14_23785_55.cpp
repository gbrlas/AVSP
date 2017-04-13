#include <cstdlib>

#include <vector>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

size_t real_war( vector < long double > & a, vector < long double > & b )
{
    const size_t n = a.size( );
    size_t cnt = 0;
    typedef vector < long double >::iterator iterator;

    iterator first = b.begin(), last = b.end( );
    vector < bool > tag( n, false ); // unavaialbel items;

    for ( size_t j = 0; j < n; ++ j )
    {
        // update first & last;
        while ( tag[ first - b.begin( ) ] )
            ++ first;

        while ( tag[ last - b.begin() - 1 ] )
            -- last;

        // first element not less than a[ j ]
        iterator iter = lower_bound( first, last, a[ j ]);

        while ( iter != last && tag[ iter - b.begin() ] )
            ++ iter;

        if ( iter == last )
            iter = first;

        tag[ iter - b.begin() ] = true; // take iter
        if ( *iter < a[ j ] )
            ++ cnt;
    }

    return cnt;
}

size_t phony_war( vector < long double > & a, vector < long double > & b )
{
    typedef vector < long double >::iterator iterator;

    iterator i = a.begin(), j = b.begin( );
    size_t cnt = 0;

    while ( i != a.end( ) )
    {
        while ( i !=  a.end() && *i < *j )
            ++ i;

        if ( i != a.end( ) )
        {
            ++ cnt;
            ++ j;
            ++ i;
        }
    }

    return cnt;
}

int main ( const int argc, char * argv [ ])
{
    fstream fin, fout;
    fin.open( "wars.in", fstream::in );
    fout.open( "wars.out", fstream::out );

    size_t n;
    fin >> n;

    for ( size_t k = 0; k < n ; ++ k )
    {
        fout << "Case #" << k + 1 << ": ";

        size_t cnt;
        fin >> cnt;
        vector < long double > a( cnt ), b( cnt );
        for ( size_t j = 0 ; j < cnt; ++ j )
            fin >> a[ j ];
        for ( size_t j = 0 ; j < cnt; ++ j )
            fin >> b[ j ];

        sort( a.begin( ), a.end( ) );
        sort( b.begin( ), b.end( ) );

        const size_t y = phony_war( a, b );
        const size_t z = real_war( a, b );
        fout << y << ' ' << z << '\n';
    }

    fin.close();
    fout.close();
}
