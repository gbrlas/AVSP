#include <stdio.h>
#include <iostream>
#define INF 0x3f3f3f3f
#define MAX 505
#define LEN 19
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define CLEAR(t) memset(t, 0, sizeof(t))

char goal[LEN+2] = "welcome to code jam";
char input[MAX];
int dp[MAX][LEN];

int main() {
    FILE *fin = fopen("codejam.in", "r"), *fout = fopen("codejam.out", "w");
    int T; fscanf(fin, "%d\n", &T);
    REP(tests, T) {
        char c; fscanf(fin, "%c", &c);
        int len = 0;
        for(; c != '\n'; fscanf(fin, "%c", &c))
            input[len++] = c;
        input[len] = 0;

        CLEAR(dp);
        REP(i, len) if (input[i] == 'w') dp[i][0] = 1;
        REP(i, len) FOR(j, 1, LEN-1)
            if (input[i] == goal[j]) 
                REP(k, i) dp[i][j] = (dp[i][j]+dp[k][j-1])%10000;

        int sum = 0;
        REP(i, len) sum = (sum+dp[i][LEN-1])%10000;
        fprintf(fout, "Case #%d: %04d\n", tests+1, sum);
    }
    return 0;
}
