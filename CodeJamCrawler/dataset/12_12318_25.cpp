#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print( const vector<int>& vec, bool sel = false ) {
    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    if( sel )
        cout << " -----> " << endl;
    else cout << endl;
}

int main() {
    int T = 0;
    cin >> T;

    for( int t=0; t<T; t++ ) {
        int n, s, p;
        cin >> n >> s >> p;

        int num = 0;
        for( int k=0; k<n; k++ ) {
            int total;
            cin >> total;

            int avg = total / 3;
            int rem = total % 3;

            vector<int> no( 3 );
            no[0] = no[1] = no[2] = avg;

            // Allocate the remaining
            for( int i=0; i<rem; i++ )
                no[i] += 1;

            //cout << total << " : ";
            //print( no );
            int max = *max_element( no.begin(), no.end() );
            if( max >= p ) {
                //cout << "selected" << endl;
                num++;
                continue;
            }

            // Increase the highest and decrease the lowest
            // THIS IS SURPRISING
            if( s ) {
                sort( no.begin(), no.end() );
                no[2]++;
                if( no[0] > 0 && no[1] > 0 ) { 
                    max = no[2];
                    if( max >= p ) {
                        //print(no, true);
                        num++;
                        s--;
                        continue;
                    }
                }
            }
        } // for

        cout << "Case #" << t+1 << ": " << num << endl;

    }
    return 0;
}
