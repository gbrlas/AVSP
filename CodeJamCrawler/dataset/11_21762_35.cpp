#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int scores[101][101];
double wp[101];
double owp[101];
double oowp[101];
int opponents[101];
int played[101];
int matchesWon[101];

int read_int() { int x; scanf("%d", &x); return x; }

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T = read_int();
    for(int tests = 1; tests <= T; ++tests) {
        memset(scores, 0, sizeof(scores));
        memset(opponents, 0, sizeof(opponents));
        memset(played, 0, sizeof(played));
        memset(matchesWon, 0, sizeof(matchesWon));
        memset(wp, 0, sizeof(wp));
        memset(owp, 0, sizeof(owp));
        memset(oowp, 0, sizeof(oowp));
        int N = read_int();
        char str[128];
        for(int i = 0; i < N; ++i) {
            scanf("%s", str);
            int won = 0;
            for(int j = 0; j < N; ++j) {
                if(str[j] == '.') continue;
                if(str[j] == '0') scores[i][j] = -1;
                else if(str[j] == '1') {
                    scores[i][j] = 1;
                    ++matchesWon[i];
                }
                opponents[i]++;
                played[i]++;
            }
            if(opponents > 0)
                wp[i] = matchesWon[i] * 1. / played[i];
        }

        for(int i = 0; i < N; ++i) {
            double wpSum = 0;
            for(int j = 0; j < N; ++j) {
                if(scores[i][j] != 0) {
                    int mPlayed = played[j] - 1;
                    int mWon = matchesWon[j];
                    if(scores[i][j] == -1) --mWon;
                    wpSum += mWon * 1. / mPlayed;
                }
            }
            owp[i] = wpSum / opponents[i];
        }

        for(int i = 0; i < N; ++i) {
            double owpSum = 0;
            for(int j = 0; j < N; ++j) 
                if(scores[i][j] != 0) owpSum += owp[j];
            oowp[i] = owpSum / opponents[i];
        }

        printf("Case #%d:\n", tests);
        for(int i = 0; i < N; ++i) {
            double res = wp[i] * 0.25 + owp[i] * 0.5 + oowp[i] * 0.25;
            printf("%.7f\n", res);
        }
    }

    return 0;
}