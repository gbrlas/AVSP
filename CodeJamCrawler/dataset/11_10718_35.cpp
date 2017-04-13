#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

//BEGINTEMPLATE_BY_SCORPIOLIU
const double PI  = acos(-1.0);
const double EPS = 1e-11;
const double INF  = 1E200;

typedef long long int64;
typedef unsigned long long uint64;

typedef pair<int,int> ipair;
#define MP(X,Y) make_pair(X,Y)
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))

#define REP(i,a) for(int i=0;i<int(a);++i)
#define REP2(i,n,m) for(int i=n;i<(int)(m);++i)
#define FORE(it,a) for (typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define ALL(a) (a).begin(),(a).end()
//ENDEMPLATE_BY_SCORPIOLIU

#define SMALL
//#define LARGE

#define FSIZE 30
double f[FSIZE];
void initF(void)
{
    f[0]=1.0;
    f[1]=1.0;
    for(int i = 2; i<FSIZE; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
}

bool getWinPos(double x, double y)
{
    if (x<y)
        swap(x,y);
    for(int i = 1; i < FSIZE; i++)
    {
        if (i%2 != 0)
        {
            if (x/y >= f[2*i]/f[2*i-1])
                return true;
        }
        else
            if (x/y <= f[2*i+1]/f[2*i])
                return false;
    }
    return false;
}

int main()
{
#ifdef SMALL
    ifstream fin("C-small-practice.in");ofstream fout("C-small-practice.out");
    //ifstream fin("A-small-attempt0.in");ofstream fout("A-small-attempt0.out");
    //freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
#endif
#ifdef LARGE
    ifstream fin("C-large-practice.in");ofstream fout("C-large-practice.out");
    //ifstream fin("A-large.in");ofstream fout("A-large.out");
    //freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
#endif
    initF();
    int N;
    fin>>N;
    int a1, a2, b1, b2;

    REP(z,N)
    {

        fout<<"Case #"<<z+1<<": ";
        //////////////////////////////////////
        int cnt = 0;
        fin>>a1>>a2>>b1>>b2;
        for(int i = a1; i <= a2; i++)
        {
            for (int j = b1; j <= b2; j++)
                if (getWinPos(i,j))
                    cnt++;
        }
        //////////////////////////////////////
        fout<<cnt<<endl;
    }


    return 0;
}
