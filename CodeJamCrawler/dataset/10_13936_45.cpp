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


int main()
{
    int T;
    scanf("%d",&T);
    for (int test=1; test<=T; ++test) {
        int l, p, c;
        scanf("%d%d%d",&l, &p, &c);
        
        ull L = l;
        ull P = p;
        ull C = c;

        int cnt = 0;
        if (L * C < P) {
            ull pow = C;
            ull product = L;
            while (product < P) {
                pow = pow * pow;
                product = (ull)L * pow;
                ++cnt;
            }
        }
        printf("Case #%d: %d\n",test, cnt);
    }
    return 0;
}