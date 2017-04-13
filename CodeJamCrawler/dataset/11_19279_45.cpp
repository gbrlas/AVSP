#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <complex>
#include <cstdio>
#include <cassert>
#include <cmath>

#if defined (__GNUC__) && (__GNUC__ <= 2)
#include <hash_map>
#include <hash_set>
#else
#include <ext/hash_map>
#include <ext/hash_set>
using namespace __gnu_cxx;
#endif
using namespace std;

#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define rep(i,n) FOR(i,0,(n)-1)
#define repd(i,n) for(int i=(n)-1;i>=0;i--)

#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) rep(i,size(c))

#define itype(c) __typeof((c).begin())
#define FORE(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x)) 

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
LL s2i(string s) { istringstream i(s); LL x; i>>x; return x; }
template<class T> string i2s(T x) { ostringstream o; o << x; return o.str(); }

#define pi acos(-1.)
#define eps 1e-7
#define inf 1000000000
#define maxn 1100
#define maxp 1100000
#define ll long long


int main()
{
    int T, N,i,j,k,m,n,sum1,sum2,suma1,suma2, temp, max,a,b,c,d,au,te;

    int Ci[1001];
    int Cx[1001];
    
   FILE *fp=fopen("C-small-attempt1.in", "r"), *ofp=fopen("output.out", "w");
   fscanf(fp, "%d", &T);
   
   rep(k,T){
            fscanf(fp, "%d", &N);
            rep(i,N) Ci[i]=0;
            rep(i,N) Cx[i]=0;
            rep(i,N) fscanf(fp, "%d", &Ci[i]);          
            
	        for(b=1;b<N;b++){  
	             te=Ci[b];
	             a=b-1;
	             while(Ci[a]>te && a>=0){
	                  Ci[a+1]=Ci[a];
	                  a--;
	                  Ci[a+1]=te;
	             }
	        }
	  
	  
	  
            
            max=0;
            rep(i,N-1){
                       
                       sum1=0;
                       sum2=0;
                       suma1=0;
                       suma2=0;
                       FOR(j,0,i) {
                                  sum1=sum1^Ci[j];
                                  suma1=suma1+Ci[j];
                       }
                       FOR(j,i+1,N-1) { 
                                    sum2=sum2^Ci[j];
                                    suma2=suma2+Ci[j];
                       }
                       if (sum1==sum2) 
                       {
                          if (suma1>suma2) temp=suma1;
                          else temp=suma2;
                          if (temp>max) max=temp;       
                       }
            }            
            if (max==0) fprintf(ofp, "Case #%d: NO\n", k+1);             
            else fprintf(ofp, "Case #%d: %d\n", k+1, max);         
   } 
}
