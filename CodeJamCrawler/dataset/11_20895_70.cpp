#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 105;
int first[2];
int cnt = 1;
struct data
{
    int x, s, next;
}d[N];

int n;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int cases, tmp;
    char in[2];
    scanf("%d", &cases);
    int steps = 1;
    while (cases--)
    {
        cnt = 1;
        memset(first, 0, sizeof(first));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s %d", in, &tmp);
            if ( in[0] == 'O' )
            {
                d[i].x = 0;
                d[i].s = tmp;
            }
            else
            {
                d[i].x = 1;
                d[i].s = tmp;
            }
        }
        for (int i = n ; i >= 1; --i)
        {
            d[i].next = first[ d[i].x ];
            first[ d[i].x ] = i;
        }

        int step[2] = {1, 1};
        int times = 0;
        for (int i = 1; i <= n; ++i)
        {
            int t = d[i].x;
            tmp = abs( d[ first[t] ].s - step[ t ] ) + 1;
            step[ t ] = d[ first[t] ].s;
            times += tmp;
            first[t] = d[ first[t] ].next;
            t ^= 1;
            if ( first[t] )
            {
                int tt = abs( d[first[t]].s - step[ t ] );
                if ( d[ first[t] ].s >= step[ t ] )
                {
                    step[ t ] += min( tt, tmp );
                }
                else
                {
                    step[ t ] -= min( tt, tmp );
                }
            }
        }
        printf("Case #%d: %d\n",steps++, times);
    }
    return 0;
}
