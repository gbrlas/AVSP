#include <cstdlib>

#include <vector>
#include <set>
#include <algorithm>

#include <iostream>
#include <fstream>

using namespace std;


int main ( const int argc, char * argv [ ])
{
    fstream fin, fout;
    fin.open( "magic-trick.in", fstream::in );
    fout.open( "magic-trick.out", fstream::out );

    size_t n, case_count = 1;
    for ( fin >> n; n > 0; -- n, ++ case_count )
    {
        vector < size_t > row( 2 );
        fin >> row[ 0 ];

        vector < size_t > grid, xgrid;

        for ( size_t i = 0; i < 4; ++ i)
            for ( size_t j = 0; j < 4 ; ++ j )
            {
                size_t num;
                fin >> num;
                if ( i + 1 == row[ 0 ] )
                    grid.push_back( num );

                // grid[ i ].insert( num );
            }
        sort( grid.begin(), grid.end() );

        fin >> row[ 1 ];
        for ( size_t i = 0; i < 4; ++ i)
            for ( size_t j = 0; j < 4 ; ++ j )
            {
                size_t num;
                fin >> num;
                if ( i + 1 == row[ 1 ] )
                    xgrid.push_back( num );
                ///xgrid[ i ].insert( num );
            }

        sort( xgrid.begin(), xgrid.end() );

        vector < size_t > join(16 );
        vector < size_t >::iterator iter;


        iter = set_intersection( grid.begin(), grid.end(), xgrid.begin(), xgrid.end(), join.begin() );


        join.resize(iter - join.begin());

        fout << "Case #" << case_count << ": ";
        if ( join.size() == 1 )
            fout << * join.begin();
        else if ( join.size() )
            fout << "Bad magician!";
        else
            fout << "Volunteer cheated!";

        fout << '\n';
    }

    fin.close();
    fout.close();
}
