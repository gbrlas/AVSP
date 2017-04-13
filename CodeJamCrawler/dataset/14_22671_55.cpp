#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    scanf("%d ", &n);

    for (int i=1; i<=n; ++i) {
        double cost, rate, goal;
        scanf("%lf %lf %lf ", &cost, &rate, &goal);
        //printf("cost = %f, rate = %f, goal = %f\n", cost, rate, goal);

        double besttime, penaltysum = 0;

        besttime = goal/2.0;

        for (int j=1; ; ++j) {
            double newbest = goal/(2.0+rate*j);
            penaltysum += cost/(2.0+rate*(j-1));
            //printf("newbest = %f, penaltysum = %f\n", newbest, penaltysum);
            newbest += penaltysum;
            if (newbest > besttime) {
                break;
            }
            
            besttime = newbest;
        }

        printf("Case #%d: %.7f\n", i, besttime);
    }
}