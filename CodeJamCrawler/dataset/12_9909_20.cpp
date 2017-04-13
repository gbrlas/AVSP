#include <cstdio>
#include <algorithm>
#define MAXN 10000

using namespace std;

bool solve()
{
    int N, d[MAXN], l[MAXN], bl[MAXN], D;
    scanf("%d", &N);
    fill(bl, bl + N, 0);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d%d", d + i, l + i);
    }
    scanf("%d", &D);
    bl[0] = d[0];
    if (2 * d[0] >= D) return true;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N && d[j] <= d[i] + bl[i]; ++j)
        {
            bl[j] = max(bl[j], min(l[j], d[j] - d[i]));
            if (bl[j] + d[j] >= D) return true;
        }
    }
    return bl[N - 1] + d[N - 1] >= D;
}

int main()
{
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);
        if (solve())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
