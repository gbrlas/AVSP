#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
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
#include <cstring> 
using namespace std; 
#define ALL(a) (a).begin(), (a).end() 
#define SZ(a) (int)(a).size() 
#define FOR(i,s,n) for(int i=(s);i<(n);++i) 
#define REP(i,n) FOR(i,0,(n)) 
#define PB(x) push_back((x)) 
#define CLR(a,v) memset((a),(v),sizeof((a))) 
typedef long long ll; 


int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int T;
    scanf("%d", &T);

    FOR(t,1,T+1)
    {
        double C, F, X;
        cin >> C >> F >> X;

        double res = 0, curr = 0;
        int k = 0;
        while(curr + 1e-7 <= X)
        {
            double toFin = (X - curr) / (k*F + 2);
            double toBy = (C - curr) / (k*F + 2);

            if (toFin + 1e-7 <= toBy)
            {
                res += toFin;
                break;
            }

            res += toBy;
            curr = C;
            double t1 = (X - curr) / (k*F + 2);
            double t2 = (X - (curr - C)) / ((k+1)*F + 2);
            if (t1 + 1e-7 <= t2)
            {
                res += t1;
                break;
            }

            ++k;
            curr = 0;
        }

        printf("Case #%d: %.7f\n", t, res);
        //cout << "Case #" << t << ": " << res << "\n";
    }

    return 0;
}
