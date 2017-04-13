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
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w+", stdout);

    int T;
    scanf("%d", &T);

    FOR(t,1,T+1)
    {
        int r1;
        set<int> s1;
        scanf("%d", &r1);
        FOR(i,1,5)
        {
            int tmp;
            REP(j,4)
            {
                scanf("%d", &tmp);
                if(i == r1)
                    s1.insert(tmp);
            }
        }

        int r2;
        set<int> s2;
        scanf("%d", &r2);
        FOR(i,1,5)
        {
            int tmp;
            REP(j,4)
            {
                scanf("%d", &tmp);
                if(i == r2)
                    s2.insert(tmp);
            }
        }

        set<int> res;
        set_intersection(ALL(s1), ALL(s2), inserter(res, res.begin()));

        if (SZ(res) == 1)
        {
            printf("Case #%d: %d\n", t, *res.begin());
        }
        else if (res.empty())
        {
            printf("Case #%d: Volunteer cheated!\n", t);
        }
        else
        {
            printf("Case #%d: Bad magician!\n", t);
        }
    }

    return 0;
}
