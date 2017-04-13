#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i =1; i <= t; ++i) {
        int o_pos = 1;
        int o_ts = 0;
        int b_pos = 1;
        int b_ts = 0;
        int last_ts = 0;
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            char b;
            int but;
            cin >> b >> but;
            if (b == 'O') {
                int delta = abs(o_pos - but);
                int new_ts = max(o_ts + delta, last_ts) + 1;
                o_pos = but;
                o_ts = new_ts;
                last_ts = new_ts;
            } else {
                int delta = abs(b_pos - but);
                int new_ts = max(b_ts + delta, last_ts) + 1;
                b_pos = but;
                b_ts = new_ts;
                last_ts = new_ts;
            }
        }
        cout << "Case #" << i << ": " << last_ts << endl;
    }
    return 0;
}
