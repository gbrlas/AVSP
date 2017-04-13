
// {{{
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long double LD;
typedef long long LL;
typedef pair<LD,LD> PD;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;

#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)

#define ALL(x) x.begin(),x.end()
#define CLR(A,v) memset((A),v,sizeof((A)))
#define FI first
#define MP make_pair
#define PB push_back
#define SE second
#define SIZE(x) ((int)(x).size())
// }}}
const int nmx=103,alf='z'-'a'+1;
char F[100];
int n,k,res;
int T[nmx][alf];
const int mod=10009;
int m;
int K[10];
int R[13];

struct czw{
    int t[4];
    czw(){
        CLR(t,0);
    }
    bool operator<(const czw &b) const{
        REP(i,4) if(t[i]!= b.t[i])
            return t[i] < b.t[i];
        return 0;
    }
    czw dod(const czw &b) const{
        czw r;
        REP(i,4) r.t[i]= t[i] + b.t[i];
        return r;
    }
};

map<czw,LL> S[2];
int rm,rlim;
int XX[4];
int XK[4];

int pot(int x,int k){
    int r=1;
    REP(d,k){
        r*=x;
        r%=mod;
    }
    return r;
}

int licz(czw slowo){
    int r=1;
    int w=0;

    for(int i=0;i< rlim; i+= XK[w++]){
        r*=pot(slowo.t[i], XK[w]);
        r%=mod;
    }
    assert(w==rm);
    return r;
}


int main()
{
    int z; scanf("%d",&z);
    
    REP(zz,z)
    {
        // ---- Cleaning !!! ----
        CLR(T,0);
        CLR(R,0);


        // ----------------------
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        scanf("%s%d",F,&k);
        scanf("%d",&n);
        char buf[103];
        REP(i,n){
            scanf("%s",buf);
            int l = strlen(buf);
            REP(j,l) T[i][buf[j]-'a']++;
        }
        int x=0;
        while(F[x]){
            m=0;
            while(F[x] && F[x]!='+'){
                K[m++]=F[x]-'a';
                x++;
            }
            if(F[x]) x++;

            rm=0;
            CLR(XK,0);
            REP(d,m){
                if(d && K[d] != K[d-1]) rm++;
                XX[rm]=K[d];
                XK[rm]++;
            }
            rm++;
            rlim=m;
/*            printf("---------------------\n");
            printf("K x:%d ",x); 
            REP(i,m) printf("%d ",K[i]);
            puts("");
            REP(i,rm) printf("%d %d  ",XX[i],XK[i]);
            puts("");
*/
            S[0].clear();
            S[1].clear();
            int ac=0, ls=1;

            

            S[0][czw()]=1;
            REP(i,k){
                REP(j,n){
                    czw now;
                    REP(y,m) now.t[y]= T[j][K[y]];
                    FORE(y, S[ac]){
                        S[ls][y->FI.dod(now)]+=y->SE;
                    }
                }    
                swap(ac,ls);
                S[ls].clear();
                int res=0;
                FORE(j, S[ac]) {res+=(licz(j->FI)*( j->SE% mod ))%mod; res%=mod; }
                R[i]+=res;
                R[i]%=mod;
  //              printf("%d\n",res);
            }
        }
        printf("Case #%d:",zz+1);
        REP(i,k){ printf(" %d",R[i]); }
        puts("");
    }
    return 0;
}
