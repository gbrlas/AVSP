#include <cstdio>
#define MAXLEN 101
#define DICT "yhesocvxduiglbkrztnwjpfmaq"
using namespace std;
int solve()
{
    int ret = 0;
    int N, S, p;
    scanf("%d%d%d", &N, &S, &p);
    for (int i = 0; i < N; ++i)
    {
        int t;
        scanf("%d", &t);
        if ((t + 2) / 3 >= p) ++ret;
        else if (S && t > 1 && t >= 3 * p - 4) ++ret, --S;
    }
    return ret;
}
int main()
{
    int T;
    scanf("%d\n", &T);
    for (int i = 1; i <= T; ++i)
    {
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
