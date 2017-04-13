#include <cstdio>
#include <algorithm>
#include <functional>
#include <cstdlib>
#define MAXN 1000

using namespace std;

int N, W, L;
long long ansx[MAXN], ansy[MAXN], r[MAXN];
bool valid()
{
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
        {
            if ((ansx[i] - ansx[j]) * (ansx[i] - ansx[j]) + (ansy[i] - ansy[j]) * (ansy[i] - ansy[j]) < (r[i] + r[j]) * (r[i] + r[j]))
            {
                return false;
            }
        }
    return true;
}
void solve()
{
    pair<int, int> students[MAXN];
    scanf("%d%d%d", &N, &W, &L);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &students[i].first);
        students[i].second = i;
        r[i] = students[i].first;
    }
    if (N == 1)
    {
        printf(" 0 0\n");
        return;
    }
    sort(students, students + N, greater<pair<int, int> >());
    ansx[students[0].second] = 0;
    ansy[students[0].second] = 0;
    ansx[students[1].second] = W;
    ansy[students[1].second] = L;
    do
    {
        for (int i = 2; i < N; ++i)
        {
            ansx[students[i].second] = rand() % (W + 1);
            ansy[students[i].second] = rand() % (L + 1);
        }
    } while (!valid());
    for (int i = 0; i < N; ++i) printf(" %lld %lld", ansx[i], ansy[i]);
    putchar('\n');
}

int main()
{
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("Case #%d:", t);
        solve();
    }
}
