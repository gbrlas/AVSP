#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd( b, a % b );
}

int down[105];
int up[105];

void ini()
{
    for (int i = 1 ; i <= 100; ++i)
    {
        int c = gcd( i, 100 );
        down[i] = 100 / c;
        up[i] = i / c;
    }
}

long long n, pd, pg;

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    ini();
    int cases;
    scanf("%d", &cases);
    int step = 1;
    while (cases--)
    {
        scanf("%lld %lld %lld",&n, &pd, &pg);
        bool good = true;
        if ( pd != 100 && pg == 100 )
        {
            good = false;
        }
        else if ( pd != 0 && pg == 0 )
        {
            good = false;
        }
        else if ( n < down[pd] ) good = false;
        printf("Case #%d: %s\n", step++, good ? "Possible" : "Broken" );
    }
    return 0;
}
