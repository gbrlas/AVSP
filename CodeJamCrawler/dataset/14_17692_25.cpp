#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    vector<long double> A;
    for (int step = 0; step < T; step++)
    {
        long double c, f, x;
        cin >> c >> f >> x;
        long double ans = 0, mn = 1000000000;
        for (long double col = 0; col < 100000; col++)
        {
            if (ans + x / (2 + col * f) < mn)
            {
                mn = ans + x / (2 + col * f);
            }
            ans +=  c / (2 + col * f);
        }
        cout.precision(20);
        cout << "Case #" << step + 1<< ": "  << mn << endl;

    }
    return 0;
}
