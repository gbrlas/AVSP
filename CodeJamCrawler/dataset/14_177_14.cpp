// YASH ARCHIT
// B.TECH 2ND YR CSE
// MNNIT ALLAHABAD
// archit.yash@gmail.com

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>

using namespace std;

#define LL long long
#define VI vector<int>
#define SIZE(C) ((int)C.size())
#define LEN(C) ((int)C.length())
#define CLR(C) memset(C, 0, sizeof(C))
#define CLRN(C) memset(C, -1, sizeof(C))
#define II pair<int, int>
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define INF (int(1e9))
#define INFL (LL(1e18))
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

#define REP(i, n) for(i = 0; i < n; i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(c) c.begin(),c.end()

#define DEB(n) cout<<"(<<< DEBUG "<<n<<" >>>)"<<endl;
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

inline void in(int &n) {
    n=0; int ch = getchar_unlocked(); int sign = 1;
    while(ch < '0' || ch > '9') { if(ch == '-') sign=-1; ch = getchar_unlocked(); }
    while(ch >= '0' && ch <= '9') { n = (n << 3) + (n << 1) + ch - '0', ch = getchar_unlocked(); }
    n = n * sign;
}

#define eps 10e-9

int main()
{
    int t,n,i,j,x,y,k=0;
    long double C,F,X;
    in(t);
    while(t--){
        k++;
        scanf("%Lf%Lf%Lf",&C,&F,&X);
        long double currRate = 2;
        long double totTime=0;
        while(1){
            if( (X/currRate) - ((C/currRate)+(X/(currRate+F))) > eps){
                totTime += C/currRate;
                currRate += F;
            }
            else{
                totTime += X/currRate;
                break;
            }
        }
        printf("Case #%d: %.7Lf\n",k,totTime);
    }
    return 0;
}
