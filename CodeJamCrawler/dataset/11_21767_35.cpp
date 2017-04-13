#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

pair<int, int> pairs[202];

int read_int() { int x; scanf("%d", &x); return x; }

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T = read_int();
    for(int tests = 1; tests <= T; ++tests) {
        int C = read_int();
        int D = read_int();
        int totPeople = 0;
        for(int i = 0; i < C; ++i) {
            pairs[i].first = read_int();
            pairs[i].second = read_int();
            totPeople += pairs[i].second;
        }
        sort(pairs, pairs + C);

        double lo = 0;
        double hi = (double) D * totPeople;
        while(abs(hi - lo) > 1e-10) {
            double mid = (lo + hi) / 2;
            double curMin = -1e16;
            bool possible = true;
            for(int i = 0; i < C; ++i) {
                int point = pairs[i].first;
                int numPeople = pairs[i].second;
                for(int j = 0; j < numPeople; ++j) {
                    double maxAchievable = point + mid;
                    if(curMin + D > maxAchievable) {
                        possible = false;
                        break;
                    }
                    curMin = max(curMin + D, point - mid);
                }
            }
            if(possible)
                hi = mid;
            else
                lo = mid;
        }

        printf("Case #%d: %f\n", tests, (lo + hi) / 2);
    }

    return 0;
}