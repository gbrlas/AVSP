#include <stdio.h>
#include <algorithm>
using namespace std;


#define MAXN 1000010
#define MAXC 300

int T,N,C,D;
int V[MAXC], P[MAXC];
double x[MAXN];
const double eps = 1e-8;

bool OK(double t)
{
    int c = 0;
    double leftmost = P[0] - t;

    for(int i=0; i<C; ++i)
    {
        for(int j=0; j<V[i]; ++j){
            double x1 = max(leftmost, P[i] - t);
            double x2 = P[i] + t;
            if(x2 < x1 - eps) return false;
            leftmost = max(leftmost, P[i] - t);
            leftmost += D;
        }
    }
    return true;
}

int main()
{
    freopen("B-small-attempt1.in" , "r" , stdin);
    freopen("BSmall.out" , "w" , stdout);
    scanf("%d" , &T);
    double tmax , tmin, tmid;
    for(int t=1; t<=T; ++t)
    {
        scanf("%d%d" , &C, &D);
        int n = 0;
        for(int i=0; i<C; ++i)
        {
            scanf("%d%d" , &P[i], &V[i]);
            n += V[i];
        }
        tmax = n*D;
        tmin = 0;
        while(tmin + eps < tmax)
        {
            tmid = (tmin + tmax)/2;
            if( OK(tmid) ) tmax = tmid;
            else tmin = tmid;
        }
        printf("Case #%d: %.8f\n" , t, (tmin+tmax)/2 );
    }
    return 0;
}
