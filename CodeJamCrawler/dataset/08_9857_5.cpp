#include <cfloat>
#include <climits>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <iostream>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <complex>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int M = 10007;
const int N = 128;

int newton[N][N];
int mas[N][N];
int bad[16][2];

void init()
{
    for (int i = 0; i < N; ++ i)
    {
        newton[i][0] = 1;
        for (int j = 1; j <= i; ++ j)
            newton[i][j] = (newton[i - 1][j] + newton[i - 1][j - 1]) % M;
    }
}

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);
    int __cases;
    cin >> __cases;
    for (int __cs = 1; __cs <= __cases; ++ __cs)
    {
        int h, w, r;
        cin >> h >> w >> r;
        for (int i = 0; i < r; ++ i)
        {
            cin >> bad[i][0] >> bad[i][1];
            bad[i][0] --; bad[i][1] --;
        }
        memset(mas, 0, sizeof(mas));
        mas[0][0] = 1;
        for (int i = 0; i < h; ++ i)
            for (int j = 0; j < w; ++ j)
            {
                for (int k = 0; k < r; ++ k)
                    if (i == bad[k][0] && j == bad[k][1])
                        mas[i][j] = 0;
                mas[i][j] %= M;
                mas[i + 2][j + 1] += mas[i][j];
                mas[i + 1][j + 2] += mas[i][j];
            }
        printf("Case #%d: %d\n", __cs, mas[h - 1][w - 1]);
    }
    return 0;
}

