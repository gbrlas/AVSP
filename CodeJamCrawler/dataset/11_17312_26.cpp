#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

#define PI 3.14159265358979323
#define INF 2123456789
#define NUL 0.0000001

#define PB push_back
#define SZ size()
#define CS c_str()
#define LEN length()
#define CLR clear()
#define EMP empty()
#define INS insert

int a[505][505];
char s[505];

int r, c, d;

bool good(int i, int j, int k){
    return i-k > 0 && i+k <= r && j-k > 0 && j+k <= c;
}

bool good2(int i, int j, int k){
    return i-k > 0 && i+k-1 <= r && j-k > 0 && j+k-1 <= c;
}

int main(){
freopen("B-small-attempt0.in", "r", stdin);
freopen("B-small-attempt0.out", "w", stdout);

int T; scanf("%d", &T);
for (int tt = 1; tt <= T; tt++){
    scanf("%d%d%d", &r, &c, &d);

    for (int i = 1; i <= r; i++){
        scanf("%s", s+1);
        for (int j = 1; j <= c; j++) a[i][j] = s[j] - '0';
    }

    int sol = 0;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++){

            for (int k = 1; good(i, j, k); k++){
                int sumX = 0, sumY = 0;
                for (int x = i-k; x <= i+k; x++)
                    for (int y = j-k; y <= j+k; y++){
                        if ((x == i-k || x == i+k) && (y == j-k || y == j+k)) continue;

                        sumX += (i - x) * a[x][y];
                        sumY += (j - y) * a[x][y];
                    }

                if (!sumX && !sumY) sol = max(sol, 2*k + 1);
            }

            for (int k = 2; good2(i, j, k); k++){
                double sumX = 0.0, sumY = 0.0;
                for (int x = i-k; x < i+k; x++)
                    for (int y = j-k; y < j+k; y++){
                        if ((x == i-k || x == i+k-1) && (y == j-k || y == j+k-1)) continue;

                        sumX += (double(i - x) - 0.5) * double(a[x][y]);
                        sumY += (double(j - y) - 0.5) * double(a[x][y]);
                        //if (i == 3 && j == 3) printf("x = %d y = %d a[x][y] = %d sumX = %lf sumY = %lf\n", x, y, a[x][y], sumX, sumY);
                    }

                //if (i == 3 && j == 3) printf("sumX = %lf sumY = %lf\n", sumX, sumY);

                if (fabs(sumX) < NUL && fabs(sumY) < NUL) sol = max(sol, 2*k);
            }
        }

    if (!sol)
        printf("Case #%d: IMPOSSIBLE\n", tt);
    else
        printf("Case #%d: %d\n", tt, sol);
}

fclose(stdin); fclose(stdout);
    return 0;
}
