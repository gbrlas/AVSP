#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define DEC(i,k) for (int i=(k); i>=0; --i)

typedef long long Int;

const double EPS = 1e-9;
const double PI = acos(-1.0);

#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))
#define FIND(m,w) ((m).find(w)!=(m).end())

int main()
{
    int T;
    cin>>T;
    while (T--) {
        int N,K;
        cin>>N>>K;
        static int test=1;
        printf("Case #%d: ",test++);
        int mask=(1<<N)-1;
        if ((K&mask)==mask) puts("ON");
        else puts("OFF");
    }
}

