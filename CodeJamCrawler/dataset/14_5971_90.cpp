#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int qq=1; qq<=T; ++qq) {
        double C, F, X;
        cin >> C >> F >> X;

        cout << "Case #" << qq << ": ";

        double best = X, t = 0, rate = 2;
        double prev, stop = -1;
        while(1) {
            // wait for cookies
            prev = stop;
            stop = t + X/rate;
            //cout << stop << '\n';
            if(stop < best) {
                best = stop;
            }

            if(prev != -1 && stop > prev) break;

            // or get a factory
            t += C/rate;
            rate += F;
        }

        printf("%.8lf\n", best);
        
    }
    return 0;
}
