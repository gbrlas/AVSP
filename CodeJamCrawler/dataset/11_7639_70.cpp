#include <stdio.h>
#include <math.h>

typedef struct
{
    char r;
    int p;
}Action;

int main()
{
    int t, n, i, sum, sum2, prev[2], c = 0;
    char last;
    Action seq[100];

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n); getchar();
        for (i = 0; i < n; ++i)
        {
            seq[i].r = getchar();
            scanf("%d", &seq[i].p);
            getchar();
        }

        prev[0] = prev[1] = 1;
        sum = sum2 = last = 0;

        for (i = 0; i < n; ++i)
        {
            if (last == seq[i].r)
            {
                if (seq[i].r == 'O')
                {
                    sum += abs(seq[i].p - prev[0]) + 1;
                    sum2 += abs(seq[i].p - prev[0]) + 1;
                }
                else if (seq[i].r == 'B')
                {
                    sum += abs(seq[i].p - prev[1]) + 1;
                    sum2 += abs(seq[i].p - prev[1]) + 1;
                }
            }
            else
            {
                if (seq[i].r == 'O' && abs(seq[i].p - prev[0]) <= sum2 ||
                        seq[i].r == 'B' && abs(seq[i].p - prev[1]) <= sum2)
                {
                    ++sum;
                    sum2 = 1;
                }
                else
                {
                    if (seq[i].r == 'O')
                        sum2 = abs(seq[i].p - prev[0]) - sum2 + 1;
                    else if (seq[i].r == 'B')
                        sum2 = abs(seq[i].p - prev[1]) - sum2 + 1;
                    sum += sum2;
                }
            }

            if (seq[i].r == 'O')
                prev[0] = seq[i].p;
            else if (seq[i].r == 'B')
                prev[1] = seq[i].p;
            last = seq[i].r;
        }

        printf("Case #%d: %d\n", ++c, sum);
    }

    return 0;
}
