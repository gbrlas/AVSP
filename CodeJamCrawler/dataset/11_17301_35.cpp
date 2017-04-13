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

char a[105][105];
double WP[105], OWP[105], OOWP[105];
int sum[105], num[105];

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

int T; scanf("%d", &T);
for (int t = 1; t <= T; t++){
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%s", a[i]+1);

        for (int i = 1; i <= n; i++){
            sum[i] = 0, num[i] = 0;
            for (int j = 1; j <= n; j++) if (a[i][j] != '.'){
                sum[i] += a[i][j] - '0';
                num[i]++;
            }
            if (!num[i]) WP[i] = 0.0;
            else WP[i] = double(sum[i]) / double(num[i]);
        }

        for (int i = 1; i <= n; i++){
            OWP[i] = 0.0;
            for (int j = 1; j <= n; j++) if (a[i][j] != '.')
                if (num[j] > 1)
                    OWP[i] += double(sum[j] - (a[j][i] - '0')) / double(num[j] - 1);
            if (num[i]) OWP[i] /= double(num[i]);
        }

        //for (int i = 1; i <= n; i++) printf("%.6lf ", WP[i]); printf("\n");
        //for (int i = 1; i <= n; i++) printf("%.6lf ", OWP[i]); printf("\n");

        for (int i = 1; i <= n; i++){
            OOWP[i] = 0.0;
            for (int j = 1; j <= n; j++) if (a[i][j] != '.')
                OOWP[i] += OWP[j];
            if (num[i]) OOWP[i] /= double(num[i]);
        }

        printf("Case #%d:\n", t);
        for (int i = 1; i <= n; i++) printf("%.10lf\n", 0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i]);
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
