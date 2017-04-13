#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define MAX 2000
using namespace std;


int main()
{
     freopen("B-small-attempt0.in", "r", stdin);
     freopen("cookie.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    int i,j,k;
    double c,f,x,r;
    double farm1;
    double nofarm1,nofarm2;

    for(i = 1;i<=t;i++)
    {
        /*for(j = 0;j  < MAX;j++)
        {
            farm[j] = 0;
            nofarm[j] = 0;
        }*/
        r = 2.0;
        farm1 = nofarm1 = nofarm2 = 0;
        scanf("%lf",&c);
        scanf("%lf",&f);
        scanf("%lf",&x);
        j = 0;
        k = 0;
        nofarm1 = farm1 + (x/r);
        farm1 = farm1 + (c/r);
        r+=f;
        while(1)
        {
             nofarm2 = farm1 + (x/r);
             if(nofarm2 > nofarm1)
                break;
            farm1 = farm1 + (c/r);
            r+=f;
            nofarm1 = nofarm2;

        }
        printf("case #%d: %.7lf\n",i,nofarm1);


    }

    return 0;
}
