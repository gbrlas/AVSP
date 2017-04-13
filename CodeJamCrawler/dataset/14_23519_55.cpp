#include <iostream>
#include <cstdio>
const double kElipse = 0.0000005;
using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) {
        double C, F, X;
        cin >> C >> F >> X;
        double sum_time = 0, speed = 2.0, time_c = 0, tmp1, tmp2;
        while(true) {
            tmp1 = X / speed + time_c;//way out
            time_c += C / speed;
            speed += F;
            tmp2 = X / speed + time_c;//buy farm
            if(tmp1 - tmp2 < kElipse) {
                sum_time = tmp1;
                break;
            }
        }
        printf("Case #%d: %.7f\n", i + 1, sum_time);
    }
    return 0;
}