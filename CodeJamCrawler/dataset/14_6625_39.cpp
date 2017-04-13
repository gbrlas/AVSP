#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <cstring>
#include <climits>
#include <map>
#include <cassert>
#define mod  1000000007
#define PHI 1000000006
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define VI vector <int>
#define VII vector < vector <int> >
#define S1(x) scanf("%llu",&x)
#define MAX 100009
#define LOGMAXN 20
#define EPS 0.000001
using namespace std;


double cal (double a, double b)
{
    return (a/b);
}

int main()
{
    //freopen ("input.txt", "r", stdin);
    freopen ("B-large.in", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int t;
    S (t);
    int ii = 1;
    while (t--) {
        cout << "Case #" << ii++<< ": ";
        double c,f,x;
        cin >> c >> f >> x;

        double tt = 0.0;
        double a = 0.0;
        double b = 2.0;

        double result = 10000000000.0;
        result = min (result, cal (x, b));
        for (int i = 1; i <= 100000; i++) {
            if (a >= c) {
                b = b + f;
                a = a-c;
                result = min (result, tt+cal(x, b));
                continue;
            }

            double rr = c-a;
            tt = tt + double(rr/b);
            a = 0.0;
            b = b + f;
            result = min (result, tt+cal(x,b));
        }
        printf ("%.7f\n", result);
    }

    return 0;
}
