#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int T;
long double C, F, X;

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%Lf %Lf %Lf", &C, &F, &X);

        long double answer = X / 2.0;
        long double time = 0;
        long double cookies = 0.0;
        long double rate = 2.0;
        for (int nf = 1; C * nf <= X; nf++) {
            time += (C - cookies) / rate;
            rate += F;
            answer = min(answer, time + (X - cookies) / rate);
        }

        printf("Case #%d: %.10Lf\n", t, answer);
    }

    return 0;
}
