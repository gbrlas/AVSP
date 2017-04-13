#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-7
#define M 1000100
//#define LL __int64
#define LL long long
#define INF 0x3fffffff
#define PI 3.1415926535898
#define MOD 1000000007

using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    cin >>T;
    for(int t = 1; t <= T; t++)
    {
        double c, f, x;
        double s = 2.0;
        double cnt = 0;
        double sum1 = 0, sum2 = 0;
        cin >>c>>f>>x;
        while(1)
        {
            sum1 = (x/s)*1.0;
            sum2 = (c/s)*1.0;
            double xx = sum2;
            s += f;
            sum2 += (x/s)*1.0;
            if(sum1 < sum2)
            {
                cnt += sum1;
                break;
            }
            cnt += xx;
        }
        printf("Case #%d: %.7lf\n", t, cnt);
    }
    return 0;
}

