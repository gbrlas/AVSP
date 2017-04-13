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
#define INF 0x7f3f3f3f
#define PI 3.1415926535898

using namespace std;

const int maxn = 10000;

int main()
{
    int T;
    freopen("B-small-attempt2.in","r",stdin);
    freopen("data.out","w",stdout);
    cin >>T;
    for(int t = 1; t <= T; t++)
    {
        int x, y, k;
        cin >>x>>y>>k;
        LL sum = 0;
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
            {
                if((i&j) < k)
                    sum++;
            }
        cout<<"Case #"<<t<<": "<<sum<<endl;
    }
    return 0;
}
