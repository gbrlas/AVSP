#include <cstdio>
#include <cmath>

int work(int x)
{
    if(x <= 0) return 0;
    if(x == 1) return 1;
    return 1 + work(x / 2);
}
int  main()
{
    freopen("B-small-attempt3.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int testcases, t;
    int L, P, C;
    scanf("%d", &testcases);
    for(t = 1; t <= testcases; t++)
    {
        scanf("%d%d%d", &L, &P, &C);
        int x;
        int temp = L;
        for(x = 1; temp * C < P; x++)
        {
            temp = temp * C;
        }
        x--;
      //  printf("x = %d\n",x);
        int res = work(x);
        printf("Case #%d: %d\n", t, res);
    }
    return 0;
}
