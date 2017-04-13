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

//Temp function list begine
inline int comp(const double &a, const double &b) {
	if (fabs(a - b) < EPS)
		return 0;
	return a > b ? 1 : -1;
}
char alpha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
int  T9[27]    = {2,22,222,3,33,333,4,44,444,5,55,555,6,66,666,7,77,777,7777,8,88,888,9,99,999,9999,0};
//Temp function list end

//#define SMALL
#define LARGE

int main()
{
#ifdef SMALL
    //ifstream fin("A-small-practice.in");ofstream fout("A-small-practice.out");
    //ifstream fin("A-small-attempt0.in");ofstream fout("A-small-attempt0.out");
    freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
#endif
#ifdef LARGE
    //ifstream fin("A-large-practice.in");ofstream fout("A-large-practice.out");
    //ifstream fin("A-large.in");ofstream fout("A-large.out");
    freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
#endif
    int N;
    cin>>N;
    REP(z,N)
    {

        cout<<"Case #"<<z+1<<": ";
        //////////////////////////////////////

        //////////////////////////////////////
        cout<<endl;
    }


    return 0;
}
