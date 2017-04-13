#include <cstdlib>

#include <limits>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <map>
#include <list>
#include <set>

#include <iostream>
#include <fstream>
#include <iterator>


#ifdef BUG
    #include "header.hpp"
#else
    #define DEBUG(var)
#endif

using namespace std;

/* ------------------------------ */
int main ( const int argc, char * argv [ ])
{
    fstream fin, fout;
    fin.open( "input.txt", fstream::in );
    fout.open( "output.txt", fstream::out );

    size_t t;
    fin >> t;
    //for( fin >> t; t > 0; -- t
    for( size_t k = 0; k < t; ++ k)
    {
        fout << "Case #" << k + 1 << ": ";
        size_t n, cap;
        fin >> n >> cap;
        vector < size_t > xs(n);
        for ( vector < size_t >::iterator j = xs.begin(); j != xs.end(); ++ j )
            fin >> *j;

        sort(xs.begin(), xs.end());
        size_t cnt = 0;
        for (size_t i = 0, j = n ; i < j && j > 0; -- j)
        {
            ++ cnt;
            if ( xs[ i ] + xs[ j - 1 ] <= cap )
                ++ i;
        }

        fout << cnt << '\n';

    }
    fin.close();
    fout.close();
}
