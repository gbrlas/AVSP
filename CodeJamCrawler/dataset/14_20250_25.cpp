#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++) {
        double C, F, X;
        cin >> C >> F >> X;

        double cur_time = 0, best_time = X / 2, 
               cur_rate = 2;
        while(cur_time < best_time) {
            best_time = min(best_time, cur_time + X / cur_rate);
            cur_time += C / cur_rate;
            cur_rate += F;
        }

        cout << fixed <<  setprecision(7) <<  "Case #" << t << ": " << 
            best_time << endl;
    }
}
