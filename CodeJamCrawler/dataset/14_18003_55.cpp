#include <iostream>
#include <cstdio>

using namespace std;


int main() {
    int t;
    cin >> t;

    for (int Case = 1; Case <= t; ++Case) {
        double c;
        double f;
        double x;

        double f_num = 0;
        double total_time = 0;
        double t1, t2, t3;
        double rate;

        cin >> c >> f >> x;

        while(true) {
            rate = 2.0 + f * f_num;

            // time needed to buy a farm
            // c / rate
            // time needed to earn all after buying a new farm
            // X / (rate + f)
            t1 = c / rate;
            t2 = x / (rate + f);
            // time needed to earn all without buying a new farm
            t3 = x / rate;

            if (t1 + t2 < t3) {
//cout << rate << " " << t1;
                total_time += t1;
                f_num += 1;
            } else {
                total_time += t3;
                break;
            }
        }

        printf("Case #%d: %.7f\n", Case, total_time);
    }
    return 0;
}
