#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <climits>
using namespace std;

#define llint long long
#define lluint unsigned long long
#define uint unsigned int
#define dbl double
#define ldbl long double
#define pint pair<int, int>
#define pllint pair<long long, long long>
#define mp make_pair
#define pb push_back

void debout()
{
#ifdef _DEBUG
    fprintf(stderr, "\n");
#endif
}

template <typename Head, typename... Tail>
void debout(Head H, Tail... T)
{
#ifdef _DEBUG
    cerr << H << ' ';
    debout(T...);
#endif
}

void stressout()
{
#ifdef _DEBUG
    printf("\n");
#endif
}

template <typename Head, typename... Tail>
void stressout(Head H, Tail... T)
{
#ifdef _DEBUG
    cout << H << ' ';
    debout(T...);
#endif
}

llint gcd(llint a, llint b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int answer = 0;
        llint a, b;

        scanf("%lld/%lld", &a, &b);
        llint d = gcd(a, b);
        a /= d;
        b /= d;
        if ((b & (b - 1)) != 0)
            answer = -1;
        else
        {
            while (a > 1)
            {
                a /= 2;
                b /= 2;
            }

            for (int j = 0; j <= 40; j++)
                if (b == (1LL << j))
                    answer = j;
        }

        printf("Case #%d: ", i + 1);
        if (answer == -1)
            printf("impossible\n");
        else
            printf("%d\n", answer);
        cerr << b << endl;
    }
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();

    fprintf(stderr, "time is %.5lf\n", (double) clock());

    return 0;
}
