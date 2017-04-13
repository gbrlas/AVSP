#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        double answer = 1000000000.0, p = 0;
        double c, f, x;
        scanf("%lf %lf %lf", &c, &f, &x);

        if (x < c)
            answer = x / 2.0;
        else
        {
            double d = 2;
            answer = x / d;
            while (true)
            {
                p += c /d;
                d += f;
                if (p + x / d > answer)
                    break;
                answer = p + x / d;
            }
        }

        printf("Case #%d: %.7lf\n", i + 1, answer);
    }


    return 0;
}
