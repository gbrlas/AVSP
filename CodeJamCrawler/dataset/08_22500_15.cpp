#include <vector>
#include <algorithm>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

typedef long long MyInt;
typedef std::vector< MyInt > IntArray;

MyInt calcMsp( IntArray&, IntArray& );
static int gDebug = 0;

int main( int argc, char* argv[] ) {
    if ( argc < 3 ) {
        cout << "Usage: " << argv[ 0 ] << " <infile> <outfile>" << endl;
        return 0;
    }
    if ( argc > 3 ) {
        gDebug = 1;
    }

    ifstream input( argv[ 1 ] );
    ofstream output( argv[ 2 ] );
    int nTestCases;
    input >> nTestCases;
    if ( gDebug ) {
        cout << "nTestCases: " << nTestCases << endl;
    }
    for ( int i = 0; i < nTestCases; ++i ) {
        int nNumbers;
        input >> nNumbers;
        if ( gDebug ) {
            cout << "test case #: " << i << "; nNumbers: " << nNumbers << endl;
        }
        IntArray x, y;
        x.reserve( nNumbers );
        y.reserve( nNumbers );
        int j;
        MyInt k;
        for ( j = 0; j < nNumbers; ++j ) {
            input >> k;
            x.push_back( k );
        }
        for ( j = 0; j < nNumbers; ++j ) {
            input >> k;
            y.push_back( k );
        }
        output << "Case #" << ( i + 1 ) << ": " << calcMsp( x, y ) << endl;
    }
    input.close();
    output.close();
}

MyInt calcMsp( IntArray& x, IntArray& y ) {
    sort( x.begin(), x.end() );
    sort( y.begin(), y.end() );
    MyInt msp = 0;
    for ( int i = 0, j = ( x.size() - 1 ); i < x.size(); ++i, --j ) {
        if ( gDebug ) {
            cout << "multiplying " << x[ i ] << " with " << y[ j ] << endl;
        }
        msp += x[ i ] * y[ j ];
    }
    return msp;
}