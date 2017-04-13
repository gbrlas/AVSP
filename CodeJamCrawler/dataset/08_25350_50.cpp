//DEDICATED TO EMMA WATSON, THE BRITISH *SUNSHINE*
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <ctime>
//#include <fstream>

#define eps 10e-10
#define INF 1000000000
#define PI 3.141592653589793238462
#define EU 2.71828182845904523536
#define sz(a) (int)a.size()
#define pb(a) push_back(a)
#define mset(a,hodnota) memset(a,hodnota,sizeof(a))
#define wh(a) a.begin(),a.end()
#define REP(i,n) for(__typeof(n) i=0;i<(n);++i)
#define REPS(i,n) for(int(i)=0;i<int(n.size());++i)
#define FOR(i,a,b) for(__typeof(b) i=(a);i<=(b);++i)
#define FORD(i,a,b) for(__typeof(a) i=(a);i>=(b);--i)
#define FORE(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

#define SQR(a) ((a)*(a))
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
typedef long long ll;
using namespace std;
#define SENT 1000000
int N,NA,NB,T;
map<int,deque<int> > L,R;
multiset<int> depL,depR;
int a,b;char c;
inline int readT()
{ 
  cin>>a>>c>>b;
  return a*60+b;
}
int main( )
{
  scanf("%d",&N);
  REP(ii,N)
  {
    scanf("%d %d %d",&T,&NA,&NB);
    L.clear(),R.clear();
    depL.clear(),depR.clear();
    REP(i,NA)
    {
      int depart=readT();
      int arrive=readT();
      L[depart].pb(arrive);      
    }  
    REP(i,NB)
    {
      int depart=readT();
      int arrive=readT();
      R[depart].pb(arrive);      
    }  
    FORE(it,L)
      sort(wh(it->second));
    FORE(it,R)
      sort(wh(it->second));
    L[SENT].pb(0);
    R[SENT].pb(0);    
    int trainL=0,trainR=0;
    map<int,deque<int> >::iterator itL=L.begin(),itR=R.begin();
    
    while(itL->fi<SENT||itR->fi<SENT)
    {
//       cout<<"ITER : "<<itL->fi<<" "<<itR->fi<<endl; 

      if (itL->fi <= itR->fi)
      {//idem z left do right
        int curT=itL->fi;
        if (sz(depL)==0||curT-T < *depL.begin())
          trainL++;
        else
          depL.erase(depL.begin());
        depR.insert(itL->se.front());
        itL->se.pop_front();
      }else
      {//idem z right do left
        int curT=itR->fi;
        if (sz(depR)==0||curT-T < *depR.begin())
          trainR++;
        else
          depR.erase(depR.begin());
        depL.insert(itR->se.front());
        itR->se.pop_front();
      }
      if (sz(itL->se)==0) itL++;
      if (sz(itR->se)==0) itR++;
      
    }
    printf("Case #%d: %d %d\n",ii+1,trainL,trainR);
  }
  
  return 0;
}
