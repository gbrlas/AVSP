#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <boost/foreach.hpp>

#define foreach BOOST_FOREACH

using namespace std;

int main()
{
    typedef unsigned long long ULL;
    ULL T, N, K;
    cin >> T;

    for (ULL t = 0 ; t < T ; ++t) {
        cin >> N >> K;
        ULL M = 1 << N;
        bool on = (K % M == M - 1);
        cout << "Case #" << t+1 << ": " << (on ? "ON" : "OFF") << endl;
    }

    return 0;
}

int main2()
{
    int T, N, K;
    cin >> T;

    for (int t = 0 ; t < T ; ++t) {
        cin >> N >> K;
        vector<int> snappers(N, 0);
        for (int k = 0 ; k < K ; ++k) {
            for (int n = N-1 ; n > 0 ; --n) {
                bool change = true;
                for (int m = 0 ; m < n ; ++m) {
                    if (!snappers[m]) {
                        change = false;
                        break;
                    }
                }
                if (change)
                    snappers[n] = !snappers[n];
            }
            snappers[0] = !snappers[0];
#if 1
            cout << k << ": ";
            copy(snappers.begin(), snappers.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
#endif
        }
        bool on = true;
        foreach (int s, snappers) {
            if (!s) {
                on = false;
                break;
            }
        }
        cout << "Case #" << t+1 << ": " << (on ? "ON" : "OFF") << endl;
    }

    return 0;
}
