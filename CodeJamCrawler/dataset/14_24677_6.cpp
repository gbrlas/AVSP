#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <stdint.h>
#include <unistd.h>
#include <ctime>
#include <climits>
using namespace std;
#define FOR(i,a,b)  for(int i=(a);i<(b);i++)
#define F(i,a)      FOR(i,0,a)
#define PB          push_back
#define MP          make_pair
#define MS(a, v) memset(a, v, sizeof a)
#define ALL(v)      v.begin(),v.end()
#define NL 			printf("\n")
#define INF (1 << 28)
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)
const double PI = acos(-1.0);
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long   LL;

int main()
{
    //time_t st=clock();
    //freopen("a.txt", "w", stdout);
    //freopen("A-small-attempt4.in.txt", "r", stdin);
    int test;
    scanf("%d",&test);
    int cas=0;
    while(test--)
    {
        int r1,r2;
        vector<int> v1;
        vector<int> v2;
        vector<int> res(5);
        vector<int>::iterator it;
        int temp;
        scanf("%d",&r1);
        F(i,4)
        {
            F(j,4)
            {
                scanf("%d",&temp);
                if(i+1==r1) v1.PB(temp);
            }
        }
        scanf("%d",&r2);
        F(i,4)
        {
            F(j,4)
            {
                scanf("%d",&temp);
                if(i+1==r2)v2.PB(temp);
            }
        }
        sort(ALL(v1));
        sort(ALL(v2));
        it=set_intersection(ALL(v1),ALL(v2),res.begin());
        res.resize(it-res.begin());
        int l=res.size();
        if(res.size()==1) printf("Case #%d: %d\n",++cas,res[0] );
        else if(!res.size()) printf("Case #%d: Volunteer cheated!\n", ++cas);
        else printf("Case #%d: Bad magician!\n",++cas);
    }

    //printf("=======================\n");
    //printf("Time: %lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
    return 0;
}