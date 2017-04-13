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
   int T, i, j, k, N,O,B,paso, pasoO, pasoB, tiempo, m, aux;
   char rp[1];
   
   
   FILE *fp=fopen("A-large.in", "r"), *ofp=fopen("output.out", "w");
   fscanf(fp, "%d", &T);
   
   rep(i,T) {
            O=1;
            B=1;
            tiempo=0;
            pasoO=0;
            pasoB=0;
            
            fscanf(fp, "%s", rp);
            N=atoi(rp);
            rep(j,N) {
                       fscanf(fp, "%s", rp);
                       
                       switch (rp[0]) {
                              case 'O':
                                   fscanf(fp, "%s", rp);
                                   paso=atoi(rp);
                                   m=1;
                                   
                                   while(m){
                                            if (paso<O) {
                                               if (pasoO==0) {
                                                             tiempo+=1; 
                                                             O-=1; // move 1 step less
                                                             pasoB+=1; // can move 1 step or wait
                                               }
                                               else {
                                                    pasoO-=1; 
                                                    O-=1; // move 1 step less
                                               }
                                               
                                            }
                                            else if (paso>O) {
                                                if (pasoO==0) {
                                                             tiempo+=1; 
                                                             O+=1; // move 1 step more
                                                             pasoB+=1; // can move 1 step or wait
                                               }
                                               else {
                                                    pasoO-=1; 
                                                    O+=1; // move 1 step more
                                               }
                                            }
                                            else if (paso==O) {  
                                                 m=0;  // push
                                                 pasoB+=1; // can move 1 step or wait
                                                 tiempo+=1;
                                                 pasoO=0;
                                            }
                                   } 
                                   break;
                                   
                              case 'B':
                                   fscanf(fp, "%s", rp);
                                   paso=atoi(rp);
                                   m=1;
                                   
                                   while(m){
                                            if (paso<B) {
                                               if (pasoB==0) {
                                                             tiempo+=1; 
                                                             B-=1; // move 1 step less
                                                             pasoO+=1; // can move 1 step or wait
                                               }
                                               else {
                                                    pasoB-=1; 
                                                    B-=1; // move 1 step less
                                               }   
                                               
                                            }
                                            else if (paso>B) {
                                                if (pasoB==0) {
                                                             tiempo+=1; 
                                                             B+=1; // move 1 step more
                                                             pasoO+=1; // can move 1 step or wait
                                               }
                                               else {
                                                    pasoB-=1; 
                                                    B+=1; // move 1 step more
                                               }  
                                               
                                            }
                                            else if (paso==B) {  
                                                 m=0;  // push
                                                 pasoO+=1; // can move 1 step or wait
                                                 tiempo+=1;
                                                 pasoB=0;
                                            }
                                   } 
                                   break;

                       }
                       
                       
            }
            fprintf(ofp, "Case #%d: %d\n", i+1, tiempo); 
            //printf("Case #%d: %d\n", i+1, tiempo);
   }
    
   
  // system("pause");
  


}
