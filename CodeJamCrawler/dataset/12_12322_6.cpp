#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <boost/dynamic_bitset.hpp>

using namespace std;

typedef boost::dynamic_bitset<> bitset;

int sum( const vector<int>& a, const bitset& bs ) {
    int total = 0;
    for( int i=0; i<bs.size(); i++ )
        if( bs[i] )
            total += a[i];

    return total;
}

int main() {
    int T;
    cin >> T;
    for( int t=0; t<T; t++ ) {
        int n;
        cin >> n;

        vector<int> a( n );
        for( int i=0; i<n; i++ ) {
            cin >> a[i];
        }
        
        bool found = false;
        unordered_map<int, vector<bitset>> hash;

        long long i = 0;
        long long max = pow( 2, n );
        for( ; i<max; i++ ) {
            bitset set( n, i );

            int total = sum( a, set );
            auto it = hash.find( total );
            if( it != hash.end() ) {
                const vector<bitset>& vb = it->second;
                for( const auto& bs: vb ) {
                    if( !bs.intersects( set ) ) {
                        cout << "Case #" << t+1 << ":" << endl;

                        for( int i=0; i<set.size(); i++ ) {
                            if( set[i] )
                                cout << a[i] << " ";
                        }
                        cout << endl;

                        for( int i=0; i<bs.size(); i++ ) {
                            if( bs[i] )
                                cout << a[i] << " ";
                        }
                        cout << endl;

                        found = true;
                        goto end;
                    }
                }
            }
            else {
                vector<bitset> vb;
                vb.push_back( set );
                hash.insert( make_pair(total, vb) );
            }
        }

        if( !found ) {
            cout << "Case #" << t+1 << ":" << endl;
            cout << "Impossible" << endl;
        }

        end:
        ;
    }
    return 0;
}
