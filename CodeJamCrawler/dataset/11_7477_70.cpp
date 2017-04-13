#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {


    int m;
    ifstream in(argv[1]);
    ofstream output("a.output");

    in >> m;
    for (int i = 0; i < m; ++i) {
        char c;
        int step = 0;
        in >> step;

        int ido = 1;
        int idb = 1;
        int ret = 0;
        int lasto = 0;
        int lastb = 0;
        char lastc = 'P';
        cout << step << endl;
        for (int j = 0; j < step; ++j) {
            char c;
            int id = 0;
            in >> c >> id;

            if (c == 'O') {
                // update ido;
                int t;
                if (lastc == 'B') {
                    t = abs(id - ido) + 1 - lastb;
                    int t0 = t;
                    t = t > 0? t: 1;
                    cout << "\tOT: " << t <<  " t0: " << t << " lastb " << lastb << endl;
                    lasto = t;
                }
                else {
                    t = abs(id - ido) + 1;
                    cout << "\tOT: " << t << endl;
                    lasto += t;
                }
                ido = id;
                ret += t;
                lastc = 'O';
//                cout << "OT: " << t << endl;
            } else {
                int t;
                if (lastc == 'O') {
                    t = abs(id - idb) + 1 - lasto;
                    t = t > 0? t:1;
                    cout << "\tBT: " << t << endl;
                    lastb = t;
                }
                else {
                    t = abs(id - idb) + 1;
                    lastb += t;
                    cout << "\tBT: " << t << endl;
                }
                ret += t;
                idb = id;
                lastc = 'B';
            }
            cout << "!!ret " << ret << endl;
        }
        output << "Case #" << i+1 << ": " << ret << endl;


    
    }


    return 1;

}
