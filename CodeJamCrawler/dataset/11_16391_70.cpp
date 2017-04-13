#include <iostream>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        // vector<unsigned long> v;
        unsigned long sum = 0;
        unsigned long x = 0;
        unsigned long m = 2000000000;
        for (int j = 0; j < n; ++j) {
            unsigned long k;
            cin >> k;
            x ^= k;
            sum += k;
            if (k < m)
                m = k;
        }
        cout << "Case #" << i << ": ";
        if (x != 0) {
            cout << "NO" << endl;
        } else {
            cout << (sum - m) << endl;
        }
    }
    return 0;
}
