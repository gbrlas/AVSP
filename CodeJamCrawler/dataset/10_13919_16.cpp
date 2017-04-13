#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull win(ull a, ull b)
{
    if (a==b) {
        return 0;
    }

    if ( a < b) {
        return win(b, a);
    }

    if (a%b == 0 ) {
        return 1;
    }

    if (a/b == 1) {
        ull d = a-b;
        if (a %d == 0 || b % d == 0) {
            return 0;
        }
        else {
            ull f = win ( b, d);
            if (f == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    else {
        ull f1 = win(a%b, b);
        ull f2 = win(b+(a%b), b);
        if (f1 == 0|| f2 == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int test=1; test<=T; ++test) {
        ull A1, A2, B1, B2;
        scanf("%llu%llu%llu%llu",&A1,&A2,&B1,&B2);
        ull count = 0;
        for (ull a=A1; a<=A2; ++a) {
            for (ull b=B1; b<=B2; ++b) {
                count += win(a,b);
            }
        }
        printf("Case #%d: %llu\n",test, count);
    }
    return 0;
}