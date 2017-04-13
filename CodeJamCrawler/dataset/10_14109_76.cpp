#include <cstdio>
#include <cstring>

long long group[1024], jump[1024], sum[1024];
int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcases, s, i, j;
    long long R, k, N;
    long long total, now, res;

    scanf("%d", &testcases);
    for(s = 1; s <= testcases; s++)
    {
        scanf("%lld%lld%lld", &R, &k, &N);
        total = 0;
        for(i = 0; i < N; i++)
        {
            scanf("%lld", &group[i]);
            total += group[i];
        }
        memset(sum, 0, sizeof(sum));
        memset(jump, 0, sizeof(jump));
        j = 0;
        for(i = 0; i < N; i++)
        {
            now = 0;
            for(j = i; now + group[j] <= k ;)
            {
                now += group[j];
                j = (j + 1) % N;
                if(j == i) break;
            }
            jump[i] = j;
            sum[i] = now;
        }
        //for(i = 0; i < N; i++) printf("%I64d %I64d\n", jump[j], sum[j]);
        res = 0;
        j = 0;
        for(i = 0; i < R; i++, j = jump[j])
            res += sum[j];
        printf("Case #%d: %I64d\n", s, res);
    }
    return 0;
}
