#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <algorithm>

#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

typedef int rec[4][4];

rec r1, r2;

int main()
{
    ios::sync_with_stdio(false);
#ifdef PC
    freopen("input.txt", "r", stdin);
    freopen("sub-1.out", "w", stdout);
#endif

    int test, t, v, w, p, q, k;

    cin >> test;
    for (t = 1; t <= test; t++)
    {
        cin >> p;
        p--;
        for (v = 0; v < 4; v++)
            for (w = 0; w < 4; w++)
                cin >> r1[v][w];

        cin >> q;
        q--;
        for (v = 0; v < 4; v++)
            for (w = 0; w < 4; w++)
                cin >> r2[v][w];

        k = 0;
        for (v = 0; v < 4; v++)
            if (find(r2[q], r2[q] + 4, r1[p][v]) != r2[q] + 4)
                k++, w = v;

        if (!cin)
        {
            cout << "wrong" << endl;
            continue;
        }

        cout << "Case #" << t << ": ";
        if (k > 1)
            cout << "Bad magician!" << endl;
        else if (k == 1)
            cout << r1[p][w] << endl;
        else
            cout << "Volunteer cheated!" << endl;
    }

    return 0;
}
