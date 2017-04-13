#include <cstdlib>

#include <vector>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main ( const int argc, char * argv [ ])
{
    fstream fin, fout;
    fin.open( "cookie.in", fstream::in );
    fout.open( "cookie.out", fstream::out );

    size_t n;
    fin >> n;

    for ( size_t j = 0; j < n; ++ j )
    {
        long double c, f, x;
        fin >> c >> f >> x;

        long double rate = 2;
        long double t = 0;
        while( true )
        {
            if ( c / rate + x / ( rate + f ) < x / rate )
            {
                t += c / rate;
                rate += f;
            }
            else
            {
                t += x / rate;
                break;
            }
        }
        fout << "Case #" << j + 1 << ": ";
        fout << setprecision( 10 ) << t << '\n';
    }
}
