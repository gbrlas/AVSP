#include <iostream>
#include <algorithm>

using namespace std;
//#define DEBUG
//
#define N 1010
int mem[N][N];

int war(double *a, double *b, int n) {
    int j = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (; j < n;) {
            if (a[i] < b[j]) {
                cnt += 1;
                j += 1;
                break;
            }
            j += 1;
        }
    }
    return n-cnt;
}

int dp(double *a, double *b, int i, int j, int n) {
    if (mem[i][j] != -1)
        return mem[i][j];
#ifdef DEBUG
    printf("%d %d\n", i, j);
#endif
    if (i == n || j == n) {
        return mem[i][j] = 0;
    }
    
    int a1 = dp(a, b, i+1, j, n);
    int a2 = dp(a, b, i, j+1, n);
    int max= a1 > a2? a1: a2;
    if (a[i] > b[j]) {
        int a3 = 1+dp(a, b, i+1, j+1, n);
        max = a3 > max? a3: max;
    } else {
        int a4 = dp(a, b, i+1, j+1, n);
        max = a4 > max? a4: max;
    }
#ifdef DEBUG
    printf("%d %d %d\n", i, j, max);
#endif
    return mem[i][j] = max;
}

int deceitiful_war(double *a, double *b, int n) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            mem[i][j] = -1;
        }
    }
    return dp(a, b, 0, 0, n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[n-1-i]) 
            cnt += 1;
        if (i + 1 >= n || a[n-1] > b[n-1-i - 1])
            break;
    }
    return n - cnt;
}



int main() {
    int t;
    double a[1010];
    double b[1010];
    cin >> t;
    for (int Case = 1; Case <= t; ++Case ) {

        int n;

        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        sort(a, a+n);
        sort(b, b+n);

        printf("Case #%d: %d %d\n", Case, deceitiful_war(a, b, n), war(a, b, n));

    }

    return 0;
}
