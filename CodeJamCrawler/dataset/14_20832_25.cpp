#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int T;
    double C, F, X;
    cout << fixed;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> C >> F >> X;
        double total_seconds = 0, rate = 2;
        while (true) {
            double time1 = X / rate, time_farm = C / rate;
            double time2 = time_farm + X / (rate + F);
            if (time1 > time2) {
                total_seconds += time_farm;
                rate += F;
            } else {
                total_seconds += time1;
                break;
            }
        }
        cout << "Case #" << i + 1 << ": " << setprecision(7) << total_seconds << "\n";
    }
}
