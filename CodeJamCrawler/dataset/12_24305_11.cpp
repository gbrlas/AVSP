#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctime>
using namespace std;

int t;
int n,a,b;
int r[1010];
int x[1010],y[1010];


int main()
{
    freopen("B-small-attempt4.in","r",stdin);
    freopen("out.txt","w",stdout);
    srand((unsigned)time(0));
    int i,j,k;
    long long p,q,o,w;
    scanf("%d", &t);
    for (k = 1;k <= t;k++)
    {
        scanf("%d%d%d", &n, &a, &b);
        for (i = 1;i <= n;i++)
        {
            scanf("%d", &r[i]);
        }
        for (i = 1;i <= n;i++)
        {
            while (1)
            {
                p = rand() % (a + 1);
                o = rand() % (a + 1);
                q = rand() % (b + 1);
                w = rand() % (b + 1);
                p = (p * o) % (a + 1);
                q = (q * w) % (b + 1);
                bool ok = 1;
                for (j = 1;j < i;j++)
                {
                    if (abs(p - x[j]) < (r[i] + r[j]) && abs(q - y[j]) < (r[i] + r[j]))
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    x[i] = p;
                    y[i] = q;
                    //printf("abc %lld %lld\n", p, q);
                    break;
                }
            }
        }
        printf("Case #%d:", k);
        for (i = 1;i <= n;i++)
            printf(" %lld %lld", x[i], y[i]);
        printf("\n");
    }
    return 0;
}
