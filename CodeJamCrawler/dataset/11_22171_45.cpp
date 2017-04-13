
#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iostream>
using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);freopen("A-large.out", "w", stdout);

    int T, N;
    char ch;
    int d;

    int i, t, k;
    int oPos = 1, bPos = 1;
    int oStep = 0, bStep = 0;
    int total = 0;

    cin >> T;

    for (t = 1; t <= T; ++t) {
        cin >> N;

        oPos = 1, bPos = 1;
        oStep = 0, bStep = 0;
        total = 0;
        for (i = 0; i < N; ++i) {
            cin >> ch >> d;
      //      cout << ch << d << endl;
            if (ch == 'O') {
      //          cout << "O!!!!!" << endl;
                k = abs(d - oPos) + 1 - oStep;
                if (k <= 0) k = 1;
                bStep += k;
                oStep = 0;
                oPos = d;
            } else {
       //         cout << "B!!!!!" << endl;
                k = abs(d - bPos) + 1 - bStep;
                if (k <= 0) k = 1;
                oStep += k;
                bStep = 0;
                bPos = d;
            }
            total += k;
        //    cout << "k=" << k << " bStep=" << bStep << " oStep=" << oStep << endl;
        //    cout << "bPos=" << bPos << " oPos=" << oPos << " total=" << total << endl;
        }
        cout << "Case #" << t << ": " << total << endl;
    }

    return 0;
}
