
// {{{
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
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

int l,d;
const int lmx=30,dmx=5003;

char S[dmx][lmx];
bool B[lmx][30];

int main()
{
    int z; 
    scanf("%d%d%d",&l,&d,&z);
    REP(i,d) scanf("%s",S[i]);
    REP(zz,z)
    {
        fprintf(stderr,"Working on %d / %d\n",zz+1,z);
        CLR(B,0);
        char buf[10000];
        scanf("%s",buf);
        int m=strlen(buf);
        int x=0,k=0;
        while(x<m){
            if (buf[x]=='('){
                x++;
                while(buf[x]!=')') B[k][buf[x++]-'a']=1;
                x++;
            }   
            else {B[k][buf[x]-'a']=1; x++;}
            k++;
        }
        assert(k==l);
        int res=0;
        REP(i,d){
            bool ok=1;
            REP(j,l) ok&=B[j][S[i][j]-'a'];
            res+=ok;
        }
        printf("Case #%d: %d\n",zz+1,res);
    }
    return 0;
}
