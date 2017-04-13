#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

piii walkways[1001];

int read_int() { int x; scanf("%d", &x); return x; }

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T = read_int();
    for(int tests = 1; tests <= T; ++tests) {
        int X = read_int();
        int S = read_int();
        int R = read_int();
        int t = read_int();
        int N = read_int();
        int totalWalkway = 0;
        for(int i = 0; i < N; ++i) {
            walkways[i].second.first = read_int();
            walkways[i].second.second = read_int();
            walkways[i].first = read_int();
            totalWalkway += (walkways[i].second.second - walkways[i].second.first);
        }
        sort(walkways, &(walkways[N]));
        double res = 0;
        double timeByRunning = (double) (X - totalWalkway) / R;
        if(timeByRunning > t) {
            res += t;
            double distRemaining = X - totalWalkway - t * R;
            res += distRemaining / S;
            for(int i = 0; i < N; ++i)
                res += (double) (walkways[i].second.second - walkways[i].second.first) / (walkways[i].first + S);
        }
        else {
            res += timeByRunning;
            double timeRemaining = t - timeByRunning;
            for(int i = 0; i < N; ++i) {
                if(timeRemaining > 0) {
                    double timeReqd = (double) (walkways[i].second.second - walkways[i].second.first) / (walkways[i].first + R);
                    if(timeReqd < timeRemaining) {
                        timeRemaining -= timeReqd;
                        res += timeReqd;
                    }
                    else {
                        res += timeRemaining;
                        double distCovered = timeRemaining * (R + walkways[i].first);
                        double distRemaining = walkways[i].second.second - walkways[i].second.first - distCovered;
                        res += distRemaining / (S + walkways[i].first);
                        timeRemaining = 0;
                    }
                }
                else {
                    res += (double) (walkways[i].second.second - walkways[i].second.first) / (walkways[i].first + S);
                }
            }
        }
        
        printf("Case #%d: %.7f\n", tests, res);
    }

    return 0;
}