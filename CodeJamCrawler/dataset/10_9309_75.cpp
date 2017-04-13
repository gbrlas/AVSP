
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>

using namespace std;

#define maxn 40

int p[maxn];

int gcd(int a, int b) {
    if (a > b)return gcd(b, a);
    if (a == 0)return b;
    return gcd(b % a, a);
}
//a>=b

bool checkit2(int a, int b) {
    if (a < b)return checkit2(b, a);
    int g = gcd(a, b), k;
    a /= g;
    b /= g;
    
    k = (lower_bound(p, p + 32, b) - p);
    
    if (p[k] == b && p[k + 1] == a) {
        return (k % 2);
    }
}

bool checkit(int a, int b) {
    if (a < b)return checkit(b, a);
    if(a-b>=b)return true;
    return !checkit(b,a-b);
}


int main() {
    freopen("C-small-attempt0.in","r",stdin);
    //freopen("C-small-attempt0.out","w",stdout);
    int ii, nn, i, j, a1, a2, b1, b2, ans;
    scanf("%d", &nn);
    p[0] = p[1] = 1;

    for (i = 2; i < 32; i++)p[i] = p[i - 1] + p[i - 2];
    //for (i = 0; i < 32; i++)printf("%d\n", p[i]);
    for (ii = 1; ii <= nn; ii++) {

        printf("Case #%d: ", ii);
        scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
        ans = 0;
        for (i = a1; i <= a2; i++)for (j = b1; j <= b2; j++){
            if (checkit(i/gcd(i,j), j/gcd(i,j))){
                //printf("%d %d\n",i/gcd(i,j),j/gcd(i,j));
                ans++;
            }
        }
        printf("%d\n", ans);
    }

}
